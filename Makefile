CFLAGS=-Wall -g

all: 
	gcc -c src/tasks.c -o bin/tasks.o
	gcc -c src/ui.c -o bin/ui.o
	gcc -o bin/tdo src/main.c bin/ui.o bin/tasks.o -lsqlite3 -lncurses
