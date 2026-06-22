CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Iinclude
SRC_DIR := src
BUILD_DIR := build
BIN := fileslicer

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all run clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

run: all
	./$(BIN)

clean:
	rm -rf $(BUILD_DIR) $(BIN)
