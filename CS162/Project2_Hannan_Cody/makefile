CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o Item.o List.o inputValidation.o menu.o
SRCS=main.cpp Item.cpp List.cpp inputValidation.cpp menu.cpp
HEADERS=Item.hpp List.hpp inputValidation.hpp menu.hpp

shoppingList: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o shoppingList

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o shoppingList
