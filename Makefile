#CC=gcc
#LIBS=-lncurses
CFLAGS=-Wall -g

all: 
	gcc -c src/tasks.c -o bin/tasks.o
	gcc -o bin/tdo src/main.c bin/tasks.o
