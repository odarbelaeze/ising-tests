#ifndef WEIGHTED_ACCUMUTATOR_TEST_H_
#define WEIGHTED_ACCUMUTATOR_TEST_H_

#include <fstream>

#include "../src/WeightedAccumulator.h"

#include <cppunit/extensions/HelperMacros.h>

class WeightedAccumulatorTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(WeightedAccumulatorTest);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testAccum);
    CPPUNIT_TEST(testAccumThrows);
    CPPUNIT_TEST(testMean);
    CPPUNIT_TEST(testMeanThrows);
    CPPUNIT_TEST(testMeansq);
    CPPUNIT_TEST(testMeansqThrows);
    CPPUNIT_TEST(testVar);
    CPPUNIT_TEST(testVarThrows);
    CPPUNIT_TEST(testStddev);
    CPPUNIT_TEST(testStddevThrows);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    void testConstructor();
    void testAccum();
    void testAccumThrows();
    void testMean();
    void testMeanThrows();
    void testMeansq();
    void testMeansqThrows();
    void testVar();
    void testVarThrows();
    void testStddev();
    void testStddevThrows();

private:
    WeightedAccumulator wa_dummy;
    WeightedAccumulator wa_data;
    std::ifstream data;

};

#endif