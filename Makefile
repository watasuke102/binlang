# binlang - basic bit operation with interactive terminal 
# Makefile
#
# CopyRight (c) 2021 - 2023 watasuke
# This program is released under the MIT or MIT SUSHI-WARE License.
#
PREFIX   := build
TARGET   := $(PREFIX)/binlang.out
OBJDIR   := $(PREFIX)/obj
INCLUDE  := inc
SRCDIR   := src
CC       := gcc
CFLAGS   := -Wall -std=c11
SOURCES  := $(wildcard src/*.c)
HEADERS  := $(wildcard inc/*.h)
OBJS     := $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))

.PHONY: all
all: $(PREFIX) $(TARGET)

$(PREFIX):
	mkdir $(PREFIX)
	mkdir $(OBJDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDE)) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf -I $(PREFIX)

test: $(TARGET)
	./test.sh
