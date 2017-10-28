$NetBSD: patch-src_irq.c,v 1.4 2016/12/07 17:28:39 fhajny Exp $

Provide a port to NetBSD.

--- src/irq.c.orig	2016-11-30 08:52:01.316911197 +0000
+++ src/irq.c
@@ -27,10 +27,20 @@
 #include "plugin.h"
 #include "utils_ignorelist.h"
 
-#if !KERNEL_LINUX
+#if !KERNEL_LINUX && !KERNEL_NETBSD
 #error "No applicable input method."
 #endif
 
+#if KERNEL_NETBSD
+
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/evcnt.h>
+#include <malloc.h>
+
+#endif /* KERNEL_NETBSD */
+
 /*
  * (Module-)Global variables
  */
@@ -79,6 +89,7 @@ static void irq_submit(const char *irq_n
   plugin_dispatch_values(&vl);
 } /* void irq_submit */
 
+#if KERNEL_LINUX
 static int irq_read(void) {
   FILE *fh;
   char buffer[1024];
@@ -171,6 +182,64 @@ static int irq_read(void) {
 
   return (0);
 } /* int irq_read */
+#endif /* KERNEL_LINUX */
+
+#if KERNEL_NETBSD
+static int
+irq_read (void)
+{
+  const int mib[4] = {
+    CTL_KERN,
+    KERN_EVCNT,
+    EVCNT_TYPE_INTR,
+    KERN_EVCNT_COUNT_NONZERO
+  };
+  size_t buflen = 0;
+  void *buf = NULL;
+  const struct evcnt_sysctl *evs, *last_evs;
+
+  for (;;) {
+    size_t newlen;
+    int error;
+
+    newlen = buflen;
+    if (buflen)
+      buf = malloc(buflen);
+    error = sysctl(mib, __arraycount(mib),
+                   buf, &newlen, NULL, 0);
+    if (error) {
+      ERROR("irq plugin: failed to get event count");
+      return -1;
+    }
+    if (newlen <= buflen) {
+      buflen = newlen;
+      break;
+    }
+    if (buf)
+            free(buf);
+    buflen = newlen;
+  }
+  evs = buf;
+  last_evs = (void*)((char *)buf + buflen);
+  buflen /= sizeof(uint64_t);
+  while(evs < last_evs
+    && buflen > sizeof(*evs) / sizeof(uint64_t)
+    && buflen >= evs->ev_len)
+  {
+    char irqname[80];
+
+    snprintf(irqname, 80, "%s-%s", evs->ev_strings,
+      evs->ev_strings + evs->ev_grouplen + 1);
+
+    irq_submit(irqname, evs->ev_count);
+
+    buflen -= evs->ev_len;
+    evs =(const void*)((const uint64_t *)evs + evs->ev_len);
+  }
+  free(buf);
+  return 0;
+}
+#endif /* KERNEL_NETBSD */
 
 void module_register(void) {
   plugin_register_config("irq", irq_config, config_keys, config_keys_num);