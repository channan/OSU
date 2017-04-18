CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o menu.o Rosters.o Fight.o Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o inputValidation.o

SRCS=main.cpp menu.cpp Rosters.cpp Fight.cpp Creature.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp inputValidation.cpp

HEADERS=menu.hpp Rosters.hpp Fight.hpp Creature.hpp Vampire.hpp Barbarian.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp inputValidation.hpp

fantasyTournament: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o fantasyTournament

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o fantasyTournament
