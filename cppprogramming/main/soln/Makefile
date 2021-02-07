# Makefile contents here

OBJ = we3_test.o ref_manager.o
LINK_TARGET = we3_solution
REBUILDABLES = $(OBJ) $(LINK_TARGET)

CC = g++
CC_FLAGS = -Wall -O2 -g 

all: $(LINK_TARGET)

$(LINK_TARGET): $(OBJ)
	$(CC) -o $(LINK_TARGET) $(OBJ)

we3_test.o: we3_test.cpp ref_manager.h
	$(CC) $(CC_FLAGS) -c we3_test.cpp

ref_manager.o: ref_manager.cpp
	$(CC) $(CC_FLAGS) -c ref_manager.cpp

clean:
	rm -f $(REBUILDABLES)