# $NetBSD: Makefile,v 1.7 2017/09/06 16:49:36 wiz Exp $

DISTNAME=	hyphen-danish
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	41113

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Danish hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	danish loadhyph-da.tex
TEX_HYPHEN_DEF+=	\\addlanguage{danish}{loadhyph-da.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['danish']={ \
			  loader='loadhyph-da.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-da.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
