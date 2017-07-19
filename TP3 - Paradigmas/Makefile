exec: dinamica.o greedy.o forcaBruta.o main.o
	 -std=c99 -pedantic dinamica.o greedy.o forcaBruta.o main.o -o exec
main.o: main.c dinamica.h greedy.h forcaBruta.h bandeira.h
	gcc -g -c main.c
dinamica.o: dinamica.c dinamica.h bandeira.h
	    gcc -g -c dinamica.c
greedy.o: greedy.c greedy.h bandeira.h
		gcc -g -c greedy.c
forcaBruta.o: forcaBruta.c forcaBruta.h bandeira.h
		gcc -g -c forcaBruta.c
clean:
	rm *.o *.gch
	rm exec
