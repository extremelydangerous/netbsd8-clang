# $NetBSD: Makefile,v 1.6 2017/06/23 17:06:33 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-${VERSION:R}.3
CATEGORIES=	sysutils
MASTER_SITES+=	http://pub.mate-desktop.org/releases/${VERSION:R}/

COMMENT=	File manager for the MATE desktop

BUILD_DEPENDS+=		gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

PKGCONFIG_OVERRIDE+=	libcaja-extension/libcaja-extension.pc.in

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../filesystems/fuse/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
