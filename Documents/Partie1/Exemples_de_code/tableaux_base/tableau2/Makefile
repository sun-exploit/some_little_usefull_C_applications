# Makefile pour la conversion d'une chaîne minuscule en majuscule
# Eric Bachard / Octobre 2014
# Sauf mention contraire, tout est place sous Licence GPL V2

CC = gcc
INCLUDE_DIR = inc
BUILD_DIR = build
APPLICATION_NAME = tableau
FILENAME = ${BUILD_DIR}/${APPLICATION_NAME}
CFLAGS = -Wall -ansi -pedantic -std=c99
LDFLAGS = -lm
CFLAGS_DEBUG = -g -DDEBUG
OBJS = *.c

all : ${FILENAME} ${FILENAME}_debug

${FILENAME}: ${OBJS}
	${CC} -I${INCLUDE_DIR} ${CFLAGS} -o $@ $^ ${LDFLAGS}

${FILENAME}_debug: ${OBJS}
	${CC} -I${INCLUDE_DIR} ${CFLAGS} ${CFLAGS_DEBUG} -o $@ $^ ${LDFLAGS}

clean:
	${RM} *.o ${FILENAME} ${FILENAME}_debug
	${RM} -rf ${BUILD_DIR}/*.dSYM
