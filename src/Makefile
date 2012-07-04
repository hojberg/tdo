CC      := gcc
CFLAGS  := -Wall -g -std=c99
OBJECTS := tasks.o ui.o
LIBS    := -lsqlite3 -lncurses

TARGET  := tdo
PROJECT := tdo

.PHONY: clean

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBS)

clean:
	@-rm -f $(OBJECTS) $(TARGET)
