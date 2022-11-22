
CC = gcc
AR = ar
CFLAGS = -Wall -g
OBJECT_MAIN = main.o
OBJECTS_LOOP = my_mat.o

.PHONY: all clean

all: libclassreq.a connections

connections: libclassreq.a $(OBJECT_MAIN)
	${CC} ${CFLAG} -L. $(OBJECT_MAIN) -lclassreq -o $@

libclassreq.a : $(OBJECTS_LOOP)
		$(AR) $(FLAGS) -rcs libclassreq.a $(OBJECTS_LOOP)


$(OBJECT_MAIN): main.c my_mat.h
	${CC} ${CFLAG} -c main.c

clean:
	rm  -f  *.o *.so *.a  connections

