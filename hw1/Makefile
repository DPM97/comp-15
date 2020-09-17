# Comp 15: Data Structures
# Tufts University
# Makefile for Homework 1

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3


build: CharArrayList.o TestCharArrayList.o
	${CXX} ${LDFLAGS} -o main CharArrayList.o testCharArrayList.o

CharArrayList.o: CharArrayList.cpp CharArrayList.h
	${CXX} ${CXXFLAGS} -c -o CharArrayList.o CharArrayList.cpp 

TestCharArrayList.o: testCharArrayList.cpp
	${CXX} ${CXXFLAGS} -c -o testCharArrayList.o testCharArrayList.cpp

clean:
	rm -f *.o main
