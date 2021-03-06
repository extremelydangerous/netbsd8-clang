$NetBSD: patch-urcu_uatomic_generic.h,v 1.1 2015/03/19 19:14:26 joerg Exp $

Clang requires correctly sized pointer arguments for the builtins.

--- urcu/uatomic/generic.h.orig	2015-03-17 21:09:40.000000000 +0000
+++ urcu/uatomic/generic.h
@@ -65,17 +65,17 @@ unsigned long _uatomic_cmpxchg(void *add
 	switch (len) {
 #ifdef UATOMIC_HAS_ATOMIC_BYTE
 	case 1:
-		return __sync_val_compare_and_swap_1(addr, old, _new);
+		return __sync_val_compare_and_swap_1((uint8_t *)addr, old, _new);
 #endif
 #ifdef UATOMIC_HAS_ATOMIC_SHORT
 	case 2:
-		return __sync_val_compare_and_swap_2(addr, old, _new);
+		return __sync_val_compare_and_swap_2((uint16_t *)addr, old, _new);
 #endif
 	case 4:
-		return __sync_val_compare_and_swap_4(addr, old, _new);
+		return __sync_val_compare_and_swap_4((uint32_t *)addr, old, _new);
 #if (CAA_BITS_PER_LONG == 64)
 	case 8:
-		return __sync_val_compare_and_swap_8(addr, old, _new);
+		return __sync_val_compare_and_swap_8((uint64_t *)addr, old, _new);
 #endif
 	}
 	_uatomic_link_error();
@@ -100,20 +100,20 @@ void _uatomic_and(void *addr, unsigned l
 	switch (len) {
 #ifdef UATOMIC_HAS_ATOMIC_BYTE
 	case 1:
-		__sync_and_and_fetch_1(addr, val);
+		__sync_and_and_fetch_1((uint8_t *)addr, val);
 		return;
 #endif
 #ifdef UATOMIC_HAS_ATOMIC_SHORT
 	case 2:
-		__sync_and_and_fetch_2(addr, val);
+		__sync_and_and_fetch_2((uint16_t *)addr, val);
 		return;
 #endif
 	case 4:
-		__sync_and_and_fetch_4(addr, val);
+		__sync_and_and_fetch_4((uint32_t *)addr, val);
 		return;
 #if (CAA_BITS_PER_LONG == 64)
 	case 8:
-		__sync_and_and_fetch_8(addr, val);
+		__sync_and_and_fetch_8((uint64_t *)addr, val);
 		return;
 #endif
 	}
@@ -139,20 +139,20 @@ void _uatomic_or(void *addr, unsigned lo
 	switch (len) {
 #ifdef UATOMIC_HAS_ATOMIC_BYTE
 	case 1:
-		__sync_or_and_fetch_1(addr, val);
+		__sync_or_and_fetch_1((uint8_t *)addr, val);
 		return;
 #endif
 #ifdef UATOMIC_HAS_ATOMIC_SHORT
 	case 2:
-		__sync_or_and_fetch_2(addr, val);
+		__sync_or_and_fetch_2((uint16_t *)addr, val);
 		return;
 #endif
 	case 4:
-		__sync_or_and_fetch_4(addr, val);
+		__sync_or_and_fetch_4((uint32_t *)addr, val);
 		return;
 #if (CAA_BITS_PER_LONG == 64)
 	case 8:
-		__sync_or_and_fetch_8(addr, val);
+		__sync_or_and_fetch_8((uint64_t *)addr, val);
 		return;
 #endif
 	}
@@ -180,17 +180,17 @@ unsigned long _uatomic_add_return(void *
 	switch (len) {
 #ifdef UATOMIC_HAS_ATOMIC_BYTE
 	case 1:
-		return __sync_add_and_fetch_1(addr, val);
+		return __sync_add_and_fetch_1((uint8_t *)addr, val);
 #endif
 #ifdef UATOMIC_HAS_ATOMIC_SHORT
 	case 2:
-		return __sync_add_and_fetch_2(addr, val);
+		return __sync_add_and_fetch_2((uint16_t *)addr, val);
 #endif
 	case 4:
-		return __sync_add_and_fetch_4(addr, val);
+		return __sync_add_and_fetch_4((uint32_t *)addr, val);
 #if (CAA_BITS_PER_LONG == 64)
 	case 8:
-		return __sync_add_and_fetch_8(addr, val);
+		return __sync_add_and_fetch_8((uint64_t *)addr, val);
 #endif
 	}
 	_uatomic_link_error();
