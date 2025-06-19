CC=gcc
CFLAGS=-Wall -Wextra -std=c11

all: parser

parser: main.o parse_module.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c parse_module.h
	$(CC) $(CFLAGS) -c -o $@ main.c

parse_module.o: parse_module.c parse_module.h
	$(CC) $(CFLAGS) -c -o $@ parse_module.c

clean:
	rm -f parser main.o parse_module.o
