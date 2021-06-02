all: main_program

main_program: main_program.cpp libmeds.o liblist.o libdatabase.o libinterface.o
	g++ main_program.cpp -o mydb libmeds.o liblist.o libdatabase.o libinterface.o

libinterface.o: interface.cpp interface.h libmeds.o liblist.o libdatabase.o
	g++ -g -c interface.cpp -o libinterface.o

libdatabase.o: database.cpp database.h libmeds.o liblist.o
	g++ -g -c database.cpp -o libdatabase.o 

liblist.o: list.cpp list.h libmeds.o
	g++ -g -c list.cpp -o liblist.o

libmeds.o: meds.cpp meds.h
	g++ -g -c -o libmeds.o meds.cpp

clean:
	rm -rf \#* *~ lib*.o mydb *.db
