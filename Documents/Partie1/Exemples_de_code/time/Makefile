# Makefile pour le projet saisie
# Eric Bachard / 2008 

CC = gcc
CFLAGS = -Wall -ansi -pedantic -std=c99
CFLAGS_DEBUG = -g -DDEBUG
OBJS = time_1.c

time1: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^

time1_debug: ${OBJS}
	${CC} ${CFLAGS} ${CFLAGS_DEBUG} -o $@ $^

clean:
	${RM} *.o time1 time1_debug
