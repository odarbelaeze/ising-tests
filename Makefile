CC = g++
CPPFLAGS = -std=c++11 -O3
OBJECTS = WeightedAccumulator.o Accumulator.o SpinMath.o System.o

all: main

run: main
	./main

main: $(OBJECTS) main.cc
	$(CC) $(CPPFLAGS) -o main main.cc $(OBJECTS)

%.o: %.cc %.h
	$(CC) $(CPPFLAGS) -c $<
