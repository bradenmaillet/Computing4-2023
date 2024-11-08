ereCC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = PhotoMagic.hpp FibLFSR.hpp
OBECTS = PhotoMagic.o main.o test.o FibLFSR.o
PROGRAM = PhotoMagic test PhotoMagic.a

all:$(PROGRAM)

%.o:%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
PhotoMagic:main.o PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB) -lm -lstdc++
test:test.o PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB) -lm -lstdc++
PhotoMagic.a:PhotoMagic.o FibLFSR.o
	ar rcs PhotoMagic.a PhotoMagic.o FibLFSR.o
clean:
	rm *.o *.a PhotoMagic test PhotoMagic.a
lint:
	cpplint *.cpp *.hpp
