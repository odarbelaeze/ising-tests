ACLOCAL_AMFLAGS = -I m4 --install

noinst_LIBRARIES = libspins.a libstats.a libsystem1D.a

libspins_a_SOURCES = src/SpinMath.cc src/SpinMath.h

libsystem1D_a_SOURCES = src/System.cc src/System.h \
                        src/SystemMC.cc src/SystemMC.h \
                        src/SpinMath.cc src/SpinMath.h

libstats_a_SOURCES = src/WeightedAccumulator.cc src/WeightedAccumulator.h \
                     src/Accumulator.cc src/Accumulator.h

TESTS = testSpin testSystem1D testWeightedAccumulator
noinst_PROGRAMS = $(TESTS)
check_PROGRAMS = $(TESTS)

testSpin_SOURCES = test/test.cc test/SpinTest.cc test/SpinTest.h
testSpin_CXXFLAGS = $(CPPUNIT_CFLAGS)
testSpin_LDADD = $(CPPUNIT_LIBS) libspins.a

testSystem1D_SOURCES = test/test.cc test/SystemTest.cc test/SystemTest.h
testSystem1D_CXXFLAGS = $(CPPUNIT_CFLAGS)
testSystem1D_LDADD = $(CPPUNIT_LIBS) libspins.a libsystem1D.a

testWeightedAccumulator_SOURCES = test/test.cc test/WeightedAccumulatorTest.cc test/WeightedAccumulatorTest.h
testWeightedAccumulator_CXXFLAGS = $(CPPUNIT_CFLAGS)
testWeightedAccumulator_LDADD = $(CPPUNIT_LIBS) libstats.a

bin_PROGRAMS = ising1D ising1DMC
ising1D_SOURCES = src/ising1D.cc
ising1D_LDADD = -lboost_program_options libspins.a libstats.a libsystem1D.a

ising1DMC_SOURCES = src/ising1DMC.cc
ising1DMC_LDADD = -lboost_program_options libspins.a libstats.a libsystem1D.a
