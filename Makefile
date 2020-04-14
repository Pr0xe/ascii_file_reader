CXX 		= g++
CC 		= $(CXX)
CXXFLAGS	= --std=c++14 -o
all:
	$(CC) freader.cpp $(CXXFLAGS) reader
	
