CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o menu.o functions.o 
SRCS=main.cpp menu.cpp functions.cpp 
HEADERS=menu.hpp functions.hpp

algorithms: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o algorithms

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o algorithms
