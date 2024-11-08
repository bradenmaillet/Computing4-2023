CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = FibLFSR.hpp
OBECTS = FibLFSR.o main.o test.o
PROGRAM = PhotoMagic test PhotoMagic.a

all:$(PROGRAM)

%.o:%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
PhotoMagic:FibLFSR.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
test:test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
PhotoMagic.a:FibLFSR.o
	ar rcs PhotoMagic.a FibLFSR.o
clean:
	rm *.o *.a PhotoMagic test
lint:
	cpplint *.cpp *.hpp
