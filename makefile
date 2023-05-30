main: matrix.o main.o
	g++ matrix.o main.o -o main

matrix.o: matrix.cpp
	g++ -std=c++11 -c matrix.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean: 
	rm *.o main