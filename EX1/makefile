# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

all: Main

Main: Graph.o Algorithms.o Queue.o PriorityQueue.o main.o
	$(CXX) $(CXXFLAGS) -o Main Graph.o Algorithms.o Queue.o PriorityQueue.o main.o

Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp

Algorithms.o: Algorithms.cpp Algorithms.hpp Graph.hpp Queue.hpp PriorityQueue.hpp
	$(CXX) $(CXXFLAGS) -c Algorithms.cpp

Queue.o: Queue.cpp Queue.hpp
	$(CXX) $(CXXFLAGS) -c Queue.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.hpp
	$(CXX) $(CXXFLAGS) -c PriorityQueue.cpp

main.o: main.cpp Algorithms.hpp Graph.hpp PriorityQueue.hpp Queue.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./Main

# Clean rule to remove object files and the executable
clean:
	rm -f Graph.o Algorithms.o Queue.o PriorityQueue.o main.o Main

.PHONY: all clean

