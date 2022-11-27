
CC = gcc
AR = ar
CFLAGS = -Wall -g
OBJECT_MAIN = main.o

.PHONY: all clean

all: connections

connections: main.c my_mat.c
	${CC} ${CFLAG} $^ -o $@

$(OBJECT_MAIN): main.c my_mat.h
	${CC} ${CFLAG} -c main.c

clean:
	rm  -f  *.o  connections

