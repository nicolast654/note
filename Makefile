CC = gcc
CFLAGS = -Wall -Wextra -std=gnu99 -I./src -I./third_party

SRC = src/note.c src/storage_json.c third_party/cJSON/cJSON.c src/utils.c
BIN = note

TEST_SRC = tests/test_note.c src/storage.c third_party/cJSON/cJSON.c
TEST_BIN = test_note

all: $(BIN)

$(BIN):
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

debug:
	$(MAKE) CFLAGS="$(CFLAGS) -g" $(BIN)

clean:
	rm -f $(BIN) $(TEST_BIN)

install:
	sudo cp $(BIN) /usr/local/bin/

test:
	$(CC) $(CFLAGS) $(TEST_SRC) -lcriterion -o $(TEST_BIN) ./$(TEST_BIN)
