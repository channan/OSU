CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o NumberList.o inputValidation.o
SRCS=main.cpp NumberList.cpp inputValidation.cpp
HEADERS=NumberList.hpp inputValidation.hpp

linkedList: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o linkedList

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o linkedList
