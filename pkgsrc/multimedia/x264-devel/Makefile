# $NetBSD: Makefile,v 1.64 2017/09/13 09:04:05 wiz Exp $

DISTNAME=	x264-snapshot-20170912-2245
PKGNAME=	${DISTNAME:S/-snapshot-/-devel-/:S/-2245$//}
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/x264/snapshots/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.videolan.org/developers/x264.html
COMMENT=	GPL licensed H.264 encoder
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/stdlib.h) && ${OPSYS} != "Linux" # XXX should be fine
CFLAGS+=	-DHAVE_STDLIB_H
.endif

# The assembler implementations don't use position independent code
# and therefore break the builds on a lot of platforms because we use
# "libtool" to create shared libraries. We therefore need to switch
# them off even if the C versions are slower.
.if ${MACHINE_ARCH} == "i386"
.  if ${OPSYS} == "SunOS" || (${OPSYS} == "NetBSD" && \
	(!empty(OS_VERSION:M[1-5].*) && empty(OS_VERSION:M5.99.*))) || \
      ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-asm
# depends on builtin functions enabled with i486 and later with GCC.
.    if ${OPSYS} == "NetBSD" && !empty(MACHINE_ARCH:Mi386)
GNU_ARCH.i386=		i486
CFLAGS+=		-march=i486
.    endif
.  else
BUILD_DEPENDS+=		nasm>=2.13.0:../../devel/nasm
.  endif
.elif ${MACHINE_ARCH} == "x86_64"
.  if ${OPSYS} == "SunOS" || (${OPSYS} == "NetBSD" && \
	(!empty(OS_VERSION:M[1-5].*) && empty(OS_VERSION:M5.99.*)))
CONFIGURE_ARGS+=	--disable-asm
.  else
BUILD_DEPENDS+=		nasm>=2.13.0:../../devel/nasm
.  endif
.endif

USE_TOOLS+=		bash gmake
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${BASH}
CONFIGURE_ARGS+=	--enable-pic	# uses libtool's -prefer-pic
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.if ${OPSYS} == "Darwin"
USE_TOOLS+=		perl
.else
CONFIGURE_ARGS+=	--disable-opencl
.endif
MAKE_ENV+=		SH=${SH:Q}

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
# XXX Consider passing this whether cross-compiling or not.
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}
.endif

BUILD_TARGET=		default
INSTALL_TARGET=		install-lib-static install-cli
INSTALLATION_DIRS=	bin
REPLACE_SH=		strip_fopt.sh version.sh

.include "../../mk/dlopen.buildlink3.mk"

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

.if !empty(USE_BUILTIN.pthread:M[Yy][Ee][Ss])
X264_BUILD_THREADS_SUPPORT=	yes
.else
X264_BUILD_THREADS_SUPPORT=	${DLOPEN_REQUIRE_PTHREADS}
.endif

SUBST_CLASSES+=		netbsd
SUBST_STAGE.netbsd=	pre-configure
SUBST_MESSAGE.netbsd=	Adding support for NetBSD.
SUBST_FILES.netbsd=	common/cpu.c
SUBST_SED.netbsd=	-e 's,SYS_OPENBSD,SYS_OPENBSD || SYS_NETBSD,'

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/strip_fopt.sh ${WRKSRC}/ && \
	${CHMOD} +x ${WRKSRC}/strip_fopt.sh

.include "../../mk/bsd.pkg.mk"
