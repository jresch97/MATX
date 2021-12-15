CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -I../

all: matx_tests.out mat4_tests.out

matx_tests.out: matx_tests.c
	$(CC) $(CFLAGS) -o $@ $^

mat4_tests.out: mat4_tests.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f matx_tests.out mat4_tests.out