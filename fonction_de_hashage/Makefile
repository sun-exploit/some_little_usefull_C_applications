# Makefile pour la création d'une pile (sous forme de table de hashage)
# Eric Bachard / Novembre 2014
# Sauf mention contraire, tout est place sous Licence GPL V2

CHASSE_AUX_BUGS=la_chasse_est_ouverte

CC = gcc
C_STANDARD = -std=c99
INCLUDE_DIR = -Iinc
SOURCES_DIR = sources
BUILD_DIR = build
APPLICATION_NAME = hash_table
FILENAME = ${BUILD_DIR}/${APPLICATION_NAME}
CFLAGS = -Wall -ansi -pedantic ${C_STANDARD}

ifdef CHASSE_AUX_BUGS
CFLAGS +=   -Wextra \
            -Wno-unused-parameter \
            -Wno-unused-function \
            -Wunused-variable \
            -Wunused-value \
            -Wshadow \
            -Wcast-qual \
            -Wcast-align \
            -Wwrite-strings \
            -Wsign-compare \
            -fms-extensions \
            -Wfloat-equal
endif

LDFLAGS = -lm
DEBUG_SUFFIX = _debug
CFLAGS_DEBUG = -g -DDEBUG
OBJS = ${SOURCES_DIR}/*.c

all : clean ${FILENAME} ${FILENAME}${DEBUG_SUFFIX}

${FILENAME}: ${OBJS}
	${CC} ${INCLUDE_DIR} ${CFLAGS} ${LDFLAGS} -o $@ $^

${FILENAME}${DEBUG_SUFFIX}: ${OBJS}
	${CC} ${INCLUDE_DIR} ${CFLAGS} ${CFLAGS_DEBUG} ${LDFLAGS} -o $@ $^

clean:
	${RM} *.o ${FILENAME} ${FILENAME}${DEBUG_SUFFIX}
