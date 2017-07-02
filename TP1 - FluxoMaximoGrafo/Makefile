exec: fordfulkerson.o main.o
	gcc -Wall -Wextra -Werror -std=c99 -pedantic fordfulkerson.o main.o -o exec
main.o: main.c fordfulkerson.h 
	gcc -g -c main.c
fordfulkerson.o: fordfulkerson.h fordfulkerson.c
	    gcc -g -c fordfulkerson.c 
clean:
	rm *.o *.gch
	rm exec
