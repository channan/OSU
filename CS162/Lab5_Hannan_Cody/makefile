CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o recursionFunctions.o menu.o inputValidation.o
SRCS=main.cpp recursionFunctions.cpp menu.cpp inputValidation.cpp
HEADERS=recursionFunctions.hpp  menu.hpp inputValidation.hpp

recursion: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o recursion

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o recursion
