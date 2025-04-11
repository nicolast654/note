CC = gcc
CFLAGS = -Wall -Wextra -std=gnu99 -I./src

SRC = src/note.c src/storage.c
BIN = note

TEST_SRC = tests/test_note.c src/storage.c
TEST_BIN = test_note

all: $(BIN)

$(BIN):
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

debug:
	$(MAKE) CFLAGS="$(CFLAGS) -g" $(BIN)

clean:
	rm -f $(BIN)

install:
	sudo cp $(BIN) /usr/local/bin/

test:
	$(CC) $(CFLAGS) $(TEST_SRC) -lcriterion -o $(TEST_BIN) ./$(TEST_BIN)
