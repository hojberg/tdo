CC      := gcc
CFLAGS  := -Wall -g -std=c99 -pedantic

all:
	#cd src; make
	$(CC) $(CFLAGS) -c src/tasks.c -o src/tasks.o
	$(CC) $(CFLAGS) -c src/ui.c -o src/ui.o
	$(CC) $(CFLAGS) -o bin/tdo src/main.c src/ui.o src/tasks.o -lsqlite3 -lncurses
	
