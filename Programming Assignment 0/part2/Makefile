all: pqueue
pqueue:	pqueue.o
	gcc pqueue.o -o pqueue
pqueue.o: pqueue.c pqueue.h
	gcc -c pqueue.c -o pqueue.o
clear:
	rm -f pqueue.o pqueue core *~