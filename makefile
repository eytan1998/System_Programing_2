CC = gcc
AR = ar
CFLAGS = -Wall -g

OBJECT_MAIN = main.o
OBJECTS_LIB = my_mat.o


.PHONY: all clean

all: connections

connections: libmy_mat.a $(OBJECT_MAIN)
	${CC} ${CFLAG} -L. $(OBJECT_MAIN) -lmy_mat -o $@

libmy_mat.a : $(OBJECTS_LIB)
	$(AR) $(FLAGS) -rcs libmy_mat.a $(OBJECTS_LIB)

$(OBJECT_MAIN): main.c my_mat.h
	${CC} ${CFLAG} -c main.c

clean:
	rm  -f  *.o  *.a  connections