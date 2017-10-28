#!/bin/bash
LD		= ld
CC		= gcc
CXX		= g++
CFLAGS	= -I include/ -c -O3 -Wall --std=c++11

all: test

string.o: string.cpp include/string.hpp
	$(CXX) $(CFLAGS) -o string.o string.cpp

test_default.o: test/test.cpp
	$(CXX) $(CFLAGS) -o test_default.o test/test.cpp
	
test_origin.o: test/test.cpp
	$(CXX) $(CFLAGS) -o test_origin.o test/test.cpp -D ORIGIN_STRING

test: test_default.o test_origin.o string.o
	$(CXX) -o test_default test_default.o string.o
	$(CXX) -o test_origin test_origin.o

clean:
	rm *.o
	rm test_default
	rm test_origin