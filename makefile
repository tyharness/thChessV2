CC = gcc
CFLAGS  = -Wall -std=c99
LIBS = -lm

default: thChessV2

thChessV2:  thChessV2.o thChessV2func.o thChessEngV2.o
	$(CC) $(CFLAGS) $(LIBS) -o thChessV2 thChessV2.o thChessV2func.o thChessEngV2.o

thChessV2.o:  thChessV2.c  thChessV2func.h
	$(CC) $(CFLAGS) $(LIBS) -c thChessV2.c

thChessV2func.o:  thChessV2func.c  thChessV2func.h 
	$(CC) $(CFLAGS) $(LIBS) -c thChessV2func.c

thChessEngV2.o:  thChessEngV2.c  thChessEngV2.h 
	$(CC) $(CFLAGS) $(LIBS) -c thChessEngV2.c




clean: 
	$(RM) ty *.o *~ thChessV2

	
