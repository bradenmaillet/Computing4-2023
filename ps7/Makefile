CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g -O3
LIB = -lboost_date_time
DEPS = 
OBJECTS = main.o
PROGRAM = ps7

.PHONY: all clean lint

all:$(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
ps7:main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
clean:
	rm *.o *.a $(PROGRAM)
lint:
	cpplint *.cpp *.hpp


