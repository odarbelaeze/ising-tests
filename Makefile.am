ACLOCAL_AMFLAGS = -I m4 --install

noinst_LIBRARIES = libspins.a libstats.a

libspins_a_SOURCES = src/SpinMath.cc src/SpinMath.h src/System.cc src/System.h
libstats_a_SOURCES = src/WeightedAccumulator.cc src/WeightedAccumulator.h \
                     src/Accumulator.cc src/Accumulator.h

bin_PROGRAMS = main
main_SOURCES = src/main.cc
main_LDADD = -lboost_program_options libspins.a libstats.a