airport.o: airport.h airport.c
	gcc -c airport.c
search.o: airport.h search.c
	gcc -c search.c
search: airport.o search.o
	gcc -o search airport.o search.o