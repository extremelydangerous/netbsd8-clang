# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.xf86-video-intel-2017-10?=	build

BUILDLINK_TREE+=	xf86-video-intel-2017-10

.if !defined(XF86_VIDEO_INTEL_2017_10_BUILDLINK3_MK)
XF86_VIDEO_INTEL_2017_10_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xf86-video-intel-2017-10+=	xf86-video-intel-2017-10>=27nb1
BUILDLINK_PKGSRCDIR.xf86-video-intel-2017-10?=	../../lzt/xf86-video-intel

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.endif	# XF86_VIDEO_INTEL_2017_10_BUILDLINK3_MK

BUILDLINK_TREE+=	-xf86-video-intel-2017-10
