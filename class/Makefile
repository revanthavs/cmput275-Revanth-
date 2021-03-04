CC=g++
CFLAGS=-c -Wall -std=c++11
EXEC = account_manager
OBJS = account.o 

all: main.cpp account.o
	$(CC) -o $(EXEC) main.cpp account.o

account.o: account.cpp account.h
	$(CC) $(CFLAGS) account.cpp

clean:
	@rm $(OBJS) $(EXEC)