# $FreeBSD$

PORTNAME=	skanlite
DISTVERSION=	2.1.0.1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION:R:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/src/COPYING

LIB_DEPENDS=	libKF5Sane.so:graphics/libksane \
		libpng.so:graphics/png

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	ecm auth config configwidgets codecs completion \
		coreaddons doctools i18n jobwidgets kio \
		service widgetsaddons xmlgui
USE_QT5=	buildtools_build qmake_build \
		core concurrent dbus gui network widgets xml

CONFLICTS_INSTALL=	skanlite-kde4

.include <bsd.port.mk>
