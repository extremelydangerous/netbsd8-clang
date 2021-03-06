$NetBSD$

--- olwm/cmdstream.c.orig	1993-06-29 05:11:43.000000000 +0000
+++ olwm/cmdstream.c
@@ -1,4 +1,3 @@
-#ident	"@(#)cmdstream.c	26.9	93/06/28 SMI"
 
 /*
  *      (c) Copyright 1989 Sun Microsystems, Inc.
@@ -51,10 +50,10 @@ static	CmdInfo		cmdInfo = {
  *      Local Forward Declarations
  * ---------------------------------------------------------------------*/
 
-Command		*MatchCommand();
-CmdAttr		*MatchAttr();
-int		EncodeAttrValue();
-int		DecodeAttrValue();
+static Command		*MatchCommand();
+static CmdAttr		*MatchAttr();
+static int		EncodeAttrValue();
+static int		DecodeAttrValue();
 
 /* ----------------------------------------------------------------------
  *      SetCmdStream
