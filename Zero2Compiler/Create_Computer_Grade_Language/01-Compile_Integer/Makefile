CC := gcc
CFLAGS = -std=c11 -g -static
TARGET = wwx01

all: $(TARGET)

$(TARGET): wwx01.c
	$(CC) $(CFLAGS) $^ -o $@

test: wwx01
	./test.sh

clean: 
	rm -f wwx01 *.o *.exe tmp* *~

.PHONY: test clean