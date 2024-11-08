CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = RandWriter.hpp
OBJECTS = RandWriter.o
PROGRAM = TextWriter test TextWriter.a

.PHONY: all clean lint test

all:$(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
TextWriter:RandWriter.o TextWriter.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
TextWriter.a:RandWriter.o TextWriter.o
	ar rcs TextWriter.a TextWriter.o RandWriter.o
test:test.o RandWriter.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
clean:
	rm *.o *.a $(PROGRAM)
lint:
	cpplint *.cpp *.hpp


