CC = g++
CPPFLAGS = -std=c++11 -O3
OBJECTS = WeightedAccumulator.o Accumulator.o SpinMath.o System.o
LDFLAGS = -lboost_program_options

all: main

run: main
	./main

debug: CPPFLAGS = -std=c++11 -g3
debug: main

main: $(OBJECTS) main.cc
	$(CC) $(CPPFLAGS) -o main main.cc $(OBJECTS) $(LDFLAGS)

%.o: %.cc %.h
	$(CC) $(CPPFLAGS) -c $<
