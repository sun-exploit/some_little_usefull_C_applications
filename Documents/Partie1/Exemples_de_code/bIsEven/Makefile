# Makefile pour etudier la parité d'un nombre
# Auteur : Eric Bachard
# Ce document est sous Licence GPL v2  Octobre 2014
# voir : http://www.gnu.org/licenses/gpl-2.0.html

BUILD_DIR = build
SOURCE_DIR = source
APPLICATION_NAME = bIsEven
BINARY_NAME = ${BUILD_DIR}/${APPLICATION_NAME}
CC = gcc
INCLUDE_DIR = inc
CFLAGS = -I${INCLUDE_DIR} -Wall -ansi -pedantic -std=c99
CFLAGS_DEBUG = -g -DDEBUG
OBJS = ${SOURCE_DIR}/*.c

all: ${BINARY_NAME} ${BINARY_NAME}_debug

${BINARY_NAME}: ${OBJS}
	@${CC} ${CFLAGS} -o $@ $^

${BINARY_NAME}_debug: ${OBJS}
	${CC} ${CFLAGS} ${CFLAGS_DEBUG} -o $@ $^

clean:
	@${RM} *.o ${BINARY_NAME} ${BINARY_NAME}_debug
	@${RM} -rf ${BINARY_NAME}_debug.dSYM
