# $FreeBSD$

PORTNAME=	kstars
DISTVERSION=	2.9.6
PORTEPOCH=	1
CATEGORIES=	astro kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE desktop planetarium

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libraw.so:graphics/libraw \
		libwcs.so:astro/wcslib
BUILD_DEPENDS=	xplanet:astro/xplanet
RUN_DEPENDS=	xplanet:astro/xplanet

USES=		cmake:outsource compiler:c++11-lib eigen:3 gettext kde:5 \
		pkgconfig tar:xz
USE_KDE=	attica auth bookmarks codecs completion config configwidgets\
		coreaddons crash dbusaddons doctools ecm guiaddons i18n \
		iconthemes init itemviews jobwidgets kio newstuff notifications \
		notifyconfig parts plotting service solid texteditor \
		widgetsaddons xmlgui
USE_QT5=	concurrent core dbus gui multimedia network opengl printsupport \
		qml quick sql svg testlib widgets xml \
		buildtools_build qmake_build

post-patch:
# climits defines ULLONG_MAX and LLONG_MAX
	${REINPLACE_CMD} -e 's#ULONG_LONG_MAX#ULLONG_MAX#g' \
			 -e 's#LONG_LONG_MAX#LLONG_MAX#g' \
		${WRKSRC}/kstars/fitsviewer/fitsdata.cpp

.include <bsd.port.mk>
