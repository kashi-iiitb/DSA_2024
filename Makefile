bst: bst.o stack.o
	gcc -o bst stack.o bst.o
bst.o:	bst.c bst.h stack.h
	gcc -c bst.c
stack.o:	stack.c stack.h
	gcc -c stack.c
