CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o FibonacciNonRecursive.o FibonacciRecursive.o

SRCS=main.cpp FibonacciNonRecursive.cpp FibonacciRecursive.cpp

HEADERS=FibonacciNonRecursive.hpp FibonacciRecursive.hpp

fibonacci: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o fibonacci

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o fibonacci
