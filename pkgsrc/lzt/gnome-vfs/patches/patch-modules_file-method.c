$NetBSD$

--- modules/file-method.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ modules/file-method.c
@@ -134,13 +134,13 @@ GET_PATH_MAX (void)
 }
 #endif
 
-#ifdef HAVE_OPEN64
+#if defined(HAVE_OPEN64) && !defined(__APPLE__)
 #define OPEN open64
 #else
 #define OPEN g_open
 #endif
 
-#if defined(HAVE_LSEEK64) && defined(HAVE_OFF64_T)
+#if (defined(HAVE_LSEEK64) && defined(HAVE_OFF64_T)) && !defined(__APPLE__)
 #define LSEEK lseek64
 #define OFF_T off64_t
 #else
