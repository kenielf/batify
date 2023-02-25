# Build Configuration
SRC = ./src
DEST = ./build
TARGET = batify

FILES = $(shell find $(SRC) -name '*.c')
OBJS := $(FILES:$(SRC)/%.c=$(DEST)/%.o)
BIN = $(DEST)/$(TARGET)

# Compiler/Linker Configuration
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow \
		 -Werror=implicit-function-declaration -Werror=builtin-declaration-mismatch \
		 -O0 -g3

LDLIBS =
LDFLAGS =

# Rules
all: build
.PHONY: clean build

clean:
	@printf "(\033[33m!\033[00m) %s\n" "Cleaning files..."
	@rm -rfv $(DEST)

$(DEST)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	@printf "(\033[33m!\033[00m) %s %s\n" "Creating object:" $@
	@$(CC) $(CFLAGS) -c $< -o $@

build: $(OBJS)
	@$(CC) $(LDFLAGS) $(LDLIBS) -o $(BIN) $(OBJS)
