PROGRAM = main
OBJS = headerfiles/UserUtil.o headerfiles/DatabaseUtil.o
CC = gcc
CFLAGS = -O2

$(PROGRAM): $(PROGRAM).o $(OBJS)
	$(CC) -o $(PROGRAM) $(PROGRAM).o $(OBJS) -lm

$(OBJS) $(PROGRAM).o: header.h

clean:
	rm -f *.o headerfiles/*.o
