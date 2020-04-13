CXX 		= g++
CC 		= $(CXX)
CXXFLAGS	= -g -Wall
all:
	$(CC) freader.cpp $(CXXFLAGS) -o reader
	
