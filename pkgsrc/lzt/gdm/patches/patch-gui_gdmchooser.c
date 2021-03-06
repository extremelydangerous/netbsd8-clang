$NetBSD$

--- gui/gdmchooser.c.orig	2010-06-03 01:06:25.000000000 +0000
+++ gui/gdmchooser.c
@@ -1128,6 +1128,13 @@ gdm_chooser_xdmcp_init (char **hosts)
 		have_ipv6 = FALSE;
 	else
 		have_ipv6 = TRUE;
+#ifdef __NetBSD__
+	/* NetBSD defaults to V6ONLY */
+	{
+	int no = 0;
+	setsockopt(sockfd, IPPROTO_IPV6, IPV6_V6ONLY, &no, sizeof(no));
+	}
+#endif
 #endif
 	if ( ! have_ipv6) {
 		if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) == -1) {
