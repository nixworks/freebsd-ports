# $FreeBSD$

PORTNAME=	purpose
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	misc kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Offers available actions for a specific purpose

LIB_DEPENDS=	libaccounts-qt5.so:net-im/libaccounts-qt5 \
		libkaccounts.so:net-im/kaccounts-integration

USES=		cmake:outsource compiler:c++11-lang gettext \
		kde:5 pkgconfig tar:xz
USE_GNOME=	intltool
USE_KDE=	config coreaddons ecm i18n kdeclarative kio service widgetsaddons
USE_QT5=	concurrent core dbus gui network qml widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
