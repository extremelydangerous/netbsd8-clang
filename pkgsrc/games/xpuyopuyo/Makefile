# $NetBSD: Makefile,v 1.49 2017/09/06 10:40:28 wiz Exp $

DISTNAME=		xpuyopuyo-0.9.8
#PKGREVISION=		1
CATEGORIES=		games x11
#MASTER_SITES=		http://chaos2.org/xpuyopuyo/
MASTER_SITES+=		http://lenin.dabney.caltech.edu./~justins/xpuyopuyo/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://chaos2.org/xpuyopuyo/
COMMENT=		Tetris-like puzzle game
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		automake autoconf gmake
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gnome	# install desktop and pixmap files
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG=${GNOME_CONFIG:Q}

GNOME_CONFIG=		${WRKDIR}/gnome-config

pre-configure:
	cd ${WRKSRC} && autoreconf --force --install
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/gnome-config \
		> ${GNOME_CONFIG}
	${CHMOD} +x ${GNOME_CONFIG}

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
