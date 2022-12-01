CC = gcc
AR = ar
CFLAGS = -Wall -g

OBJECT_MAIN = main.o
OBJECTS_LIB = my_mat.o


.PHONY: all clean

all: connections

connections: libclassmat.a $(OBJECT_MAIN)
	${CC} ${CFLAG} -L. $(OBJECT_MAIN) -lclassmat -o $@

libclassmat.a : $(OBJECTS_LIB)
	$(AR) $(FLAGS) -rcs libclassmat.a $(OBJECTS_LIB)

$(OBJECT_MAIN): main.c my_mat.h
	${CC} ${CFLAG} -c main.c

clean:
	rm  -f  *.o  *.a  connections