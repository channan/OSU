CXX=g++
CXXFLAGS=-std=c++0x

OBJS=readMatrix.o determinant.o main.o
SRCS=readMatrix.cpp determinant.cpp main.cpp
HEADERS=readMatrix.hpp determinant.hpp

matrixDeterminant: $(OBJS) $(HEADERS)
	$(CXX) $(OBJS) -o matrixDeterminant

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o matrixDeterminant
