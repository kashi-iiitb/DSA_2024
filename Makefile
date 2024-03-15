all: bst
bst: bst.o stack.o queue.o
	gcc -g -o bst stack.o queue.o bst.o
bst.o:	bst.c bst.h stack.h queue.h
	gcc -g -c bst.c
stack.o: stack.c stack.h
	gcc -g -c stack.c
queue.o: queue.c queue.h
	gcc -g -c queue.c
clean:
	rm *.o bst
