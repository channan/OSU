CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o Die.o LoadedDie.o Game.o menu.o inputValidation.o
SRCS=main.cpp Die.cpp LoadedDie.cpp Game.cpp menu.cpp inputValidation.cpp
HEADERS=Die.hpp LoadedDie.hpp Game.hpp menu.hpp inputValidation.hpp

War: $(OBJS) $(HEADERS)
	$(CXX) $(OBJS) -o War

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o War
