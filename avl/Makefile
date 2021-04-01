CC=g++
LFLAGS=
CFLAGS=-c -std=c++11 -Wall -O2
OBJS=avlmaptest.o
PROJ=avlmaptest

$(PROJ): $(OBJS)
	$(CC) $(OBJS) -o $(PROJ) $(LFLAGS)

avlmaptest.o: avlmaptest.cpp avlmap.h avlaux.h
	$(CC) avlmaptest.cpp -o avlmaptest.o $(CFLAGS)

clean:
	@rm -f $(OBJS) $(PROJ)
