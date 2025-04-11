
CC = gcc
CFLAGS = -Wall

run: maxSubArray.c
	$(CC) $(CFLAGS) -o subarr maxSubArray.c

gprof: maxSubArray.c
	$(CC) $(CFLAGS) -pg -o subarr maxSubArray.c

clean:
	rm -f subarr gmon.out analysis.txt

# Profile and show output (you can pass ARGS="100000 42")
profile: gprof
	./subarr $(ARGS)
	gprof subarr gmon.out > analysis.txt
	cat analysis.txt
