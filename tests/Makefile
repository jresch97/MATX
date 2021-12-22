CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -I../

all: matx_tests.out mat4x_tests.out

matx_tests.out: matx_tests.c
	$(CC) $(CFLAGS) -o $@ $^

mat4x_tests.out: mat4x_tests.c
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f matx_tests.out mat4x_tests.out