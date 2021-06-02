final: mainlab.o lab.o menu.o
	gcc mainlab.o lab.o menu.o -o final

lab.o: lab.c lab.h
	gcc -c lab.c -o lab.o

menu.o: menu.c lab.h
	gcc -c menu.c -o menu.o

mainlab.o: mainlab.c lab.h
	gcc -c mainlab.c -o mainlab.o

clean: rm mainlab.o lab.o menu.o
