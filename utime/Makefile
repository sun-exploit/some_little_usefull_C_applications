# makefile, to illustrate a precise ticks
# Copyright : Eric Bachard  sept 2016
# License : GPL v2

# simple Makefile, to start with make ...
BUILD_DIR = build
VERSION_MAJOR = 0
VERSION_MINOR = 3
VERSION_MICRO = 0_devel
VERSION = ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_MICRO}

SOURCES_DIR = sources
APPLICATION_NAME = utime
BINARY_NAME = ${BUILD_DIR}/${APPLICATION_NAME}
CC = gcc
CC_FLAGS = -Wall
CC_STD = -std=c99
OS_FLAGS =

OUTBIN = ${BUILD_DIR}/${APPLICATION_NAME}
OUTBIN_DEBUG = ${BUILD_DIR}/${APPLICATION_NAME}_debug
OUTBIN_ALL = 	$(OUTBIN) 	$(OUTBIN_DEBUG)

INCLUDE_DIR = -Iinc

OBJS = ${SOURCES_DIR}/*.c

DEPS = $^

#GCC_SECURITY_FLAGS = -fstack-protector -pie -fPIE -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security

CFLAGS = ${CC_FLAGS} ${CC_STD} ${OS_FLAGS}
CFLAGS_DEBUG = -g -DDEBUG

ARCHIVE_EXT = .tar.gz

TO_BE_ZIPPED = \
    inc \
    sources \
    Makefile

TO_BE_ZIPPED_BINARIES = \
    ${BUILD_DIR}


all : $(OUTBIN_ALL)

$(OUTBIN) : $(OBJS)
	$(CC) $(CFLAGS) ${GCC_SECURITY_FLAGS} $(INCLUDE_DIR) -o $@ $(DEPS)  $(LD_FLAGS)

$(OUTBIN_DEBUG) : $(OBJS)
	$(CC) $(CFLAGS) ${GCC_SECURITY_FLAGS} $(CFLAGS_DEBUG) $(INCLUDE_DIR) -o $(OUTBIN_DEBUG) $(DEPS) $(LD_FLAGS)

clean :
	rm -rf $(BUILD_DIR)/*.o
	rm -rf $(OUTBIN) $(OUTBIN_DEBUG) ${EXEC_NAME}_${VERSION}
	rm -rf $(BUILD_DIR)/dbg*.dSYM
	rm -rf ${APPLICATION_NAME}_${VERSION}
	echo Fichiers binaires supprimés.

devel: clean
	mkdir ${APPLICATION_NAME}_${VERSION}
	mkdir -p ${APPLICATION_NAME}_${VERSION}/build
	cp -R ${TO_BE_ZIPPED} ${APPLICATION_NAME}_${VERSION}
	tar cvzf ${APPLICATION_NAME}_${VERSION}${ARCHIVE_EXT} ${APPLICATION_NAME}_${VERSION}

archive : all
	mkdir ${APPLICATION_NAME}_${VERSION}
	cp -R ${TO_BE_ZIPPED} ${APPLICATION_NAME}_${VERSION}
	cp -R ${TO_BE_ZIPPED_BINARIES} ${APPLICATION_NAME}_${VERSION}
	tar cvzf ${APPLICATION_NAME}_${VERSION}${ARCHIVE_EXT} ${APPLICATION_NAME}_${VERSION}

real_clean : clean
	rm -rf ${APPLICATION_NAME}_*${ARCHIVE_EXT}

