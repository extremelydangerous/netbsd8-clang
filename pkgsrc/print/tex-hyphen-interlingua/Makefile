# $NetBSD: Makefile,v 1.7 2017/09/06 16:49:37 wiz Exp $

DISTNAME=	hyphen-interlingua
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Interlingua
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	interlingua loadhyph-ia.tex
TEX_HYPHEN_DEF+=	\\addlanguage{interlingua}{loadhyph-ia.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['interlingua']={ \
			  loader='loadhyph-ia.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-ia.pat.txt', \
			  hyphenation='hyph-ia.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
