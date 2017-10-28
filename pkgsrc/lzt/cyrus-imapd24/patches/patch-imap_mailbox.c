$NetBSD$

--- imap/mailbox.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ imap/mailbox.c
@@ -1960,10 +1960,10 @@ bit32 make_sync_crc(struct mailbox *mail
 	flagcrc ^= crc32_cstring(buf);
     }
 
-    snprintf(buf, 4096, "%u " MODSEQ_FMT " %lu (%u) %lu %s",
-	    record->uid, record->modseq, record->last_updated,
+    snprintf(buf, 4096, "%u " MODSEQ_FMT " " MODSEQ_FMT " (%u) " MODSEQ_FMT " %s",
+	    record->uid, record->modseq, (modseq_t)record->last_updated,
 	    flagcrc,
-	    record->internaldate,
+	    (modseq_t)record->internaldate,
 	    message_guid_encode(&record->guid));
 
     return crc32_cstring(buf);
