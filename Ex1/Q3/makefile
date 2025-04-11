CC = gcc
CFLAGS = -Wall -std=c99 -fPIC
LDFLAGS = -shared
LIBNAME = libmandelbrot.so

all: libmandelbrot.so mandelbrotUsage

libmandelbrot.so: mandelbrotlib.o
	$(CC) $(LDFLAGS) -o $@ $^

mandelbrotlib.o: mandelbrotLib.c mandelbrotLib.h
	$(CC) $(CFLAGS) -c mandelbrotLib.c -o mandelbrotlib.o

mandelbrotUsage: mandelbrotUsage.c libmandelbrot.so
	$(CC) -Wall -std=c99 -o $@ mandelbrotUsage.c -L. -lmandelbrot -lm

clean:
	rm -f mandelbrotlib.o libmandelbrot.so mandelbrotUsage
