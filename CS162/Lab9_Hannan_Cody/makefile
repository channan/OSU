CXX=g++
CXXFLAGS=-std=c++11

OBJS=main.o menu.o Buffer.o Palindrome.o inputValidation.o 
SRCS=main.cpp menu.cpp Buffer.cpp Palindrome.cpp inputValidation.cpp 
HEADERS=menu.hpp Buffer.hpp Palindrome.hpp inputValidation.hpp

bufferAndPalindrome: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o bufferAndPalindrome

$(OBJS):$(SRCS)	
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm *o bufferAndPalindrome
