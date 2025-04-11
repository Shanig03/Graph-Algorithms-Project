CC = gcc
CFLAGS = -Wall -g
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage


all: dijkstra

dijkstra: dijkstra.c
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -o $@ $^

coverage: dijkstra
	./dijkstra
	gcov dijkstra.c
	cat dijkstra.c.gcov

run: clean
	$(CC) $(CFLAGS) -o dijkstra dijkstra.c
	./dijkstra

clean:
	rm -f dijkstra *.o *.gcno *.gcda *.gcov

.PHONY: all clean coverage run
