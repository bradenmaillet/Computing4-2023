CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = Sokoban.hpp
OBJECTS = Sokoban.o
PROGRAM = Sokoban test Sokoban.a

.PHONY: all clean lint test

all:$(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
Sokoban:Sokoban.o main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
Sokoban.a:Sokoban.o
	ar rcs Sokoban.a Sokoban.o
test:test.o Sokoban.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
clean:
	rm *.o *.a $(PROGRAM)
lint:
	cpplint *.cpp *.hpp


