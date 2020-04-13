CXX 		= g++
CC 		= $(CXX)
CXXFLAGS	= --std=c++14
all:
	$(CC) freader.cpp $(CXXFLAGS) -o reader
	
