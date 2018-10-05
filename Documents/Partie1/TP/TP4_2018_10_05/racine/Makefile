# Makefile générique
# Eric Bachard / Novembre 2004
# Sauf mention contraire, tout est place sous Licence GPL V2

CC = gcc
C_STANDARD = -std=c99
INCLUDE_DIR = inc
SOURCES_DIR = sources
BUILD_DIR = build
APPLICATION_NAME = second_degre
FILENAME = ${BUILD_DIR}/${APPLICATION_NAME}
CFLAGS = -Wall -ansi -pedantic ${C_STANDARD}
LDFLAGS = -lm
DEBUG_SUFFIX = _debug
CFLAGS_DEBUG = -g -DDEBUG

OBJS = ${SOURCES_DIR}/*.c

all : ${FILENAME} ${FILENAME}${DEBUG_SUFFIX}

${FILENAME}: ${OBJS}
	${CC} -I${INCLUDE_DIR} ${CFLAGS} -o $@ $^ ${LDFLAGS}

${FILENAME}${DEBUG_SUFFIX}: ${OBJS}
	${CC} -I${INCLUDE_DIR} ${CFLAGS} ${CFLAGS_DEBUG} -o $@ $^ ${LDFLAGS}

clean:
	${RM} *.o ${FILENAME} ${FILENAME}${DEBUG_SUFFIX}
	${RM} -rf ${BUILD_DIR}/*.dSYM
