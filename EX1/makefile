# Email: shanig7531@gmail.com

CXX = clang++ # Compiler
CXXFLAGS = -std=c++11 -Wall -g # Flags

all: Main

Main: Graph.o Algorithms.o Queue.o PriorityQueue.o UnionFind.o main.o 
	$(CXX) $(CXXFLAGS) -o Main Graph.o Algorithms.o Queue.o PriorityQueue.o UnionFind.o main.o

Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp

Algorithms.o: Algorithms.cpp Algorithms.hpp Graph.hpp Queue.hpp PriorityQueue.hpp UnionFind.hpp
	$(CXX) $(CXXFLAGS) -c Algorithms.cpp

Queue.o: Queue.cpp Queue.hpp
	$(CXX) $(CXXFLAGS) -c Queue.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.hpp
	$(CXX) $(CXXFLAGS) -c PriorityQueue.cpp

UnionFind.o: UnionFind.cpp UnionFind.hpp
	$(CXX) $(CXXFLAGS) -c UnionFind.cpp

main.o: main.cpp Algorithms.hpp Graph.hpp PriorityQueue.hpp Queue.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./Main

clean:
	rm -f Graph.o Algorithms.o Queue.o PriorityQueue.o UnionFind.o main.o Main

.PHONY: all clean
