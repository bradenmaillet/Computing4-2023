CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = Universe.hpp CelestialBody.hpp
OBJECTS = Universe.o CelestialBody.o
PROGRAM = NBody test NBody.a

.PHONY: all clean lint test

all:$(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
NBody:Universe.o CelestialBody.o main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
NBody.a:Universe.o CelestialBody.o
	ar rcs NBody.a Universe.o CelestialBody.o
test:test.o Universe.o CelestialBody.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
clean:
	rm *.o *.a $(PROGRAM)
lint:
	cpplint *.cpp *.hpp


