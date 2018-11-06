# Makefile permettant de créer le projet Learn_It
# Pour les auteurs, voir la documentation et la licence jointe
# Eric Bachard / Novembre 2014
# Sauf mention contraire, tout est place sous Licence GPL V2

CC = gcc
C_STANDARD = -std=c99
INCLUDE_DIR = inc
SOURCES_DIR = sources
RESSOURCE_DIR = ressources
BUILD_DIR = build
APPLICATION_NAME = Learn_It
FILENAME = ${BUILD_DIR}/${APPLICATION_NAME}
CFLAGS = -Wall -ansi -pedantic ${C_STANDARD}
LDFLAGS = -lm
DEBUG_SUFFIX = _debug
CFLAGS_DEBUG = -g -DDEBUG
FILES = ${SOURCES_DIR}/*.c

all : ${FILENAME} ${FILENAME}${DEBUG_SUFFIX}

${FILENAME}: ${FILES}
	${CC} ${CFLAGS} -o $@ $^ -I${INCLUDE_DIR} ${LDFLAGS}

${FILENAME}${DEBUG_SUFFIX}: ${FILES}
	${CC} ${CFLAGS} ${CFLAGS_DEBUG} -o $@ $^ -I${INCLUDE_DIR} ${LDFLAGS}

clean:
	${RM} *.o ${FILENAME} ${FILENAME}${DEBUG_SUFFIX}
	${RM} -rf ${BUILD_DIR}/*.dSYM
