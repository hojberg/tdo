CC=gcc
CFLAGS=-Wall -g -std=c99

all: 
	$(CC) $(CFLAGS) -c src/tasks.c -o bin/tasks.o
	$(CC) $(CFLAGS) -c src/ui.c -o bin/ui.o
	$(CC) $(CFLAGS) -o bin/tdo src/main.c bin/ui.o bin/tasks.o -lsqlite3 -lncurses
