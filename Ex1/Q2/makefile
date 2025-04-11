CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic
LDFLAGS = -lm

all: mandelbrot

mandelbrot: Mandelbrot.c
	$(CC) $(CFLAGS) -o mandelbrot Mandelbrot.c $(LDFLAGS)

run: all
	./mandelbrot

clean:
	rm -f mandelbrot