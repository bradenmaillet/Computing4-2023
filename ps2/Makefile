CC = g++
CFLAGS = --std=c++17 -Wall -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++
DEPS = PTree.hpp
OBECTS = main.o PTree.o
PROGRAM = PTree

all:$(PROGRAM)

%.o:%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
PTree:main.o PTree.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
clean:
	rm *.o *.a $(PROGRAM)
lint:
	cpplint *.cpp *.hpp

