main: main.o
	gcc -o main main.c main.c
	rm*.o
main.o: main.c
	gcc -c main.c
