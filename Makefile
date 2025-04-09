CC = gcc
CFLAGS = -g -Wall -Wextra -std=gnu99 -I./src

SRC = src/note.c src/storage.c
BIN = note

all: $(BIN)

$(BIN):
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)

install:
	sudo cp $(BIN) /usr/local/bin/
