CFLAGS = -Wall -g -ansi -O2 -std=c99

ex_dll: ex_dll.o doubly_linked.o
	$(CC) -o $@ ex_dll.o doubly_linked.o

c: clean

clean:
	rm -rf ex_dll *.o *~ 