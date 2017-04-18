CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o Building.o Instructor.o People.o Student.o University.o menu.o inputValidation.o
SRCS=main.cpp Building.cpp Instructor.cpp People.cpp Student.cpp University.cpp menu.cpp inputValidation.cpp
HEADERS=Building.hpp Instructor.hpp People.hpp Student.hpp University.hpp menu.hpp inputValidation.hpp

Uni: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o Uni

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o Uni
