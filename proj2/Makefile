### Makefile For SixDegrees
### Author:  Dylan Maloy

CXX      = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3

### fetches all .files in dir
INCLUDES = $(shell echo *.h) 
EXECS    = SixDegrees

### $@ - get cmd name
### $< get first operator
### $^ gets operators on top line

SixDegrees: main.o SixDegrees.o Artist.o CollabGraph.o
	${CXX} ${LDFLAGS} $^ -o $@

Testing: mainTesting.o Testing.o SixDegrees.o Artist.o CollabGraph.o 
	${CXX} ${LDFLAGS} $^ -o $@ 

%.o: %.cpp ${INCLUDES}
	${CXX} ${CXXFLAGS} -c -o $@ $<

providephase1: 
	provide comp15 proj2phase1 \
	Artist.cpp Artist.h CollabGraph.cpp CollabGraph.h main.cpp Makefile README \
	SixDegrees.cpp SixDegrees.h artists.txt input.txt

.PHONY: clean
clean:
	rm -f ${EXECS} *.o *.dSYM./

### compile cylc files
%.cylc:  %.cyl
	./cylc $^
