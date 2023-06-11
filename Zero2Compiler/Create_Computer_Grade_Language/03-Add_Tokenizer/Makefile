CFLAGS = -std=c11 -g -w -static

wwx: wwx.c

test: wwx
	./test.sh

clean: 
	rm -f wwx *.o *~ tmp*

.PHONY: test clean