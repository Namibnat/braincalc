CFLAGS= -g -Wall
brain: brain.h help.c

.PHONY:
clean:
	rm -rf brain *.o *~

.PHONY:
test: brain
	./brain 10