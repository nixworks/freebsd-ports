# $FreeBSD$

PORTNAME=	libkcompactdisc
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for interfacing with audio CDs

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	coreaddons ecm emoticons i18n itemmodels itemviews \
		kdelibs4support solid
USE_QT5=	core dbus phonon4\
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ALSA

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_ALSA

.include <bsd.port.mk>
