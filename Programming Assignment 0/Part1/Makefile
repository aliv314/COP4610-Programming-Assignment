all: queue
queue:	queue.o
	gcc queue.o -o queue
queue.o:	queue.c queue.h
	gcc -c queue.c -o queue.o
clean:
	rm -f queue queue.o core *~

