# $FreeBSD$

PORTNAME=	opencollada
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.47
PORTREVISION=	2
CATEGORIES=	graphics devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading and writing COLLADA files

LICENSE=	MIT

BROKEN_sparc64=	cannot build: runaway process

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake:outsource compiler:c++11-lib  dos2unix iconv pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	OpenCOLLADA

USE_GNOME=	libxml2
USE_LDCONFIG=	${PREFIX}/lib/opencollada
CFLAGS+=	-I/${LOCALBASE}/include -Wno-narrowing
CMAKE_ARGS+=	-DUSE_SHARED:BOOL=ON -DUSE_STATIC:BOOL=OFF

# for files/patch-2d66943
DOS2UNIX_FILES=	COLLADABaseUtils/include/COLLADABUPcreCompiledPattern.h \
		COLLADABaseUtils/src/COLLADABUURI.cpp

post-patch:
	@${REINPLACE_CMD} -e 's|$${OPENCOLLADA_INST_LIBRARY}/cmake|${PREFIX}/share/cmake/Modules|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
