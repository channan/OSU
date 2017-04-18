CXX=g++
CXXFLAGS=-std=c++11

OBJS=playAnt.o Ant.o main.o
SRCS=playAnt.cpp Ant.cpp main.cpp
HEADERS=playAnt.hpp Ant.hpp

Ant: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o Ant

$(OBJS):$(SRCS)	
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *o Ant
