###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Dylan Maloy

CXX      = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3

### fetches all .files in dir
INCLUDES = $(shell echo *.h) 
EXECS    = CalcYouLater

### $@ - get cmd name
### $< get first operator
### $^ gets operators on top line

CalcYouLater: main.o RPNCalc.o DatumStack.o Datum.o
	${CXX} ${LDFLAGS} $^ -o $@

Testing: mainTesting.o testing.o RPNCalc.o DatumStack.o Datum.o 
	${CXX} ${LDFLAGS} $^ -o $@

%.o: %.cpp ${INCLUDES}
	${CXX} ${CXXFLAGS} -c -o $@ $<

.PHONY: clean
clean:
	rm -f ${EXECS} *.o *.dSYM./

### compile cylc files
%.cylc:  %.cyl
	./cylc $^
