CC = g++
CPPFLAGS = -Wall -std=c++11

main: matrix.o main.o
	${CC} matrix.o main.o -o main

matrix.o: matrix/matrix.cpp
	${CC} ${CPPFLAGS} -c matrix/matrix.cpp

main.o: main.cpp
	${CC} ${CPPFLAGS} -c main.cpp

clean: 
	rm *.o main