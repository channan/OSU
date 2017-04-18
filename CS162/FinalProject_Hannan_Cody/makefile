CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o Room.o Game.o NorthRoom.o SouthRoom.o EastRoom.o WestRoom.o OpenNorthRoom.o FinaleRoom.o CentralRoom.o 

SRCS=main.cpp Room.cpp Game.cpp NorthRoom.cpp SouthRoom.cpp EastRoom.cpp WestRoom.cpp OpenNorthRoom.cpp FinaleRoom.cpp CentralRoom.cpp 

HEADERS=Room.hpp Game.hpp NorthRoom.hpp SouthRoom.hpp EastRoom.hpp WestRoom.hpp OpenNorthRoom.hpp FinaleRoom.hpp CentralRoom.hpp 

ruins: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o ruins

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o ruins
