# $FreeBSD$

PORTNAME=	wspr
DISTVERSION=	${VERSION}.r${SVN_REV}
PORTREVISION=	10
CATEGORIES=	comms hamradio
MASTER_SITES=	LOCAL/db
DISTNAME=	wspr-r${SVN_REV}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal for HF ham radio communication package

LICENSE=	GPLv3

BROKEN_aarch64=		fails to compile: gfortran6: unrecognized command line option '-m64'

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
LIB_DEPENDS=	libhamlib.so:comms/hamlib \
		libfftw3f.so:math/fftw3-float \
		libsamplerate.so:audio/libsamplerate \
		libportaudio.so:audio/portaudio

MAKE_JOBS_UNSAFE=	yes
USES=		autoreconf dos2unix fortran gmake libtool python:3.3+ tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gfortran=${FC} \
		--with-f2py=f2py-${PYTHON_VER} \
		--with-python3=${PYTHON_CMD}
MAKE_ENV+=	PYTHONUSERBASE=${STAGEDIR}${PYTHONBASE}
#LDFLAGS+=	-shared
VERSION=	4.00

.include <bsd.port.pre.mk>
pre-configure:
	@${CP} ${FILESDIR}/wspr.sh.in ${WRKSRC}

do-build:
	(cd ${WRKSRC};${GMAKE})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/wspr/WsprMod/w.so

.if defined(BOOTSTRAP)
#portlint freaks over this but it's only for dev ignore.
SVN_REV!=	svn info svn://svn.code.sf.net/p/wsjt/wsjt/branches/wspr | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		svn://svn.code.sf.net/p/wsjt/wsjt/branches/wspr ${WRKDIR}/wspr-r${SVN_REV}
	cd ${WRKDIR};rm -f ${DISTNAME}/*.a ${DISTNAME}/*.lib ${DISTNAME}/*.dll;\
		tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == db
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
		freefall.freebsd.org:public_distfiles/
.endif
.endif

.include <bsd.port.post.mk>
