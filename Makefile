bst: bst.o stack.o queue.o
	gcc -o bst stack.o queue.o bst.o
bst.o:	bst.c bst.h stack.h queue.h
	gcc -c bst.c
stack.o: stack.c stack.h
	gcc -c stack.c
queue.o: queue.c queue.h
	gcc -c queue.c
