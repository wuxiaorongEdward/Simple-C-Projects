main: main.o menu.o bank.o
	gcc main.o menu.o bank.o -o main

main.o: main.c
	gcc -c main.c

menu.o: menu.c
	gcc -c menu.c

bank.o: bank.c
	gcc -c bank.c

clear:
	- rm *.o

