main: matrix.o main.o
	g++ matrix.o main.o -o main

matrix.o: matrix.cpp
	g++ -c matrix.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm *.o main