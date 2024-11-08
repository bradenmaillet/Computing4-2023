CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = EDistance.hpp
OBJECTS = EDistance.o
PROGRAM = EDistance test EDistance.a

.PHONY: all clean lint test

all:$(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
EDistance:EDistance.o main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
EDistance.a:EDistance.o
	ar rcs EDistance.a EDistance.o
test:test.o EDistance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
clean:
	rm *.o *.a $(PROGRAM)
lint:
	cpplint *.cpp *.hpp


