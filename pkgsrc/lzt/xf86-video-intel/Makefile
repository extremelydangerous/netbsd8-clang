# $NetBSD: Makefile,v 1.39 2016/12/07 21:59:54 wiz Exp $

PKGNAME=	xf86-video-intel-2017-10-27
DISTFILES=	xf86-video-intel-2017-10-27.tar.gz
DISTDIR=	${FILESDIR}
PKGREVISION=	1
CATEGORIES=	lzt
MASTER_SITES=

EXTRACT_SUFX=	.tar.gz

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver

CONFLICTS+=	xf86-video-i810-[0-9]*

CONFIGURE_ARGS+=	--disable-silent-rules \
			--enable-kms-only \
			--enable-dri \
			--enable-uxa \
			--enable-sna

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config autoconf automake autoreconf

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../x11/modular-xorg-server/buildlink3.mk"
#.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
