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

	# Add test rule
Test.o: Test.cpp doctest.h Graph.hpp Algorithms.hpp Queue.hpp PriorityQueue.hpp
	$(CXX) $(CXXFLAGS) -c Test.cpp

Test: Graph.o Algorithms.o Queue.o PriorityQueue.o UnionFind.o Test.o
	$(CXX) $(CXXFLAGS) -o Test Graph.o Algorithms.o Queue.o PriorityQueue.o UnionFind.o Test.o

test: Test
	./Test

valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./Main

clean:
	rm -f Graph.o Algorithms.o Queue.o PriorityQueue.o UnionFind.o main.o Test.o Main Test

.PHONY: all clean test
