CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o menu.o Queue.o inputValidation.o

SRCS=main.cpp menu.cpp Queue.cpp inputValidation.cpp

HEADERS=menu.hpp Queue.hpp inputValidation.hpp

queue: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o queue

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o queue
