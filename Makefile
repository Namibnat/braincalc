CFLAGS= -g -Wall
brain: brain.h help.c

.PHONY : clean
clean:
	rm -rf brain *.o *~