#include "WeightedAccumulatorTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(WeightedAccumulatorTest);

void WeightedAccumulatorTest::setUp()
{
    wa_data = WeightedAccumulator();

    std::ifstream data;
    data.open("test/datatest");

    double x;
    double w;

    while(data >> x >> w)
    {
        wa_data.accum(x, w);
    }
    data.close();

}
void WeightedAccumulatorTest::tearDown() {}

void WeightedAccumulatorTest::testConstructor()
{
    wa_dummy = WeightedAccumulator();
    CPPUNIT_ASSERT_EQUAL(0.0, wa_dummy.getData());
    CPPUNIT_ASSERT_EQUAL(0.0, wa_dummy.getDatasq());
    CPPUNIT_ASSERT_EQUAL(0.0, wa_dummy.getWeights());
}


void WeightedAccumulatorTest::testAccum()
{
    CPPUNIT_ASSERT(std::abs(16.0981053214212 - wa_data.getDatasq()) < 1.0e-13);
    CPPUNIT_ASSERT(std::abs(24.8352594640656 - wa_data.getData()) < 1.0e-13);
    CPPUNIT_ASSERT(std::abs(49.2961508464068 - wa_data.getWeights()) < 1.0e-13);
}


void WeightedAccumulatorTest::testAccumThrows()
{
    CPPUNIT_ASSERT_THROW(wa_dummy.accum(10, -1), InvalidWeightException);
}


void WeightedAccumulatorTest::testMean()
{
    CPPUNIT_ASSERT(std::abs(0.503797132994123 - wa_data.mean()) < 1.0e-15);
}


void WeightedAccumulatorTest::testMeanThrows()
{
    wa_dummy = WeightedAccumulator();
    CPPUNIT_ASSERT_THROW(wa_dummy.mean(), NoDataException);
}


void WeightedAccumulatorTest::testMeansq()
{
    CPPUNIT_ASSERT(std::abs(0.326559072970594 - wa_data.meansq()) < 1.0e-15);
}


void WeightedAccumulatorTest::testMeansqThrows()
{
    wa_dummy = WeightedAccumulator();
    CPPUNIT_ASSERT_THROW(wa_dummy.mean(), NoDataException);
}


void WeightedAccumulatorTest::testVar()
{
    CPPUNIT_ASSERT(std::abs(0.0727475217574953 - wa_data.var()) < 1.0e-15);
}


void WeightedAccumulatorTest::testVarThrows()
{
    wa_dummy = WeightedAccumulator();
    CPPUNIT_ASSERT_THROW(wa_dummy.mean(), NoDataException);
}


void WeightedAccumulatorTest::testStddev()
{
    CPPUNIT_ASSERT(std::abs(0.269717485079287 - wa_data.stddev()) < 1.0e-15);
}


void WeightedAccumulatorTest::testStddevThrows()
{
    wa_dummy = WeightedAccumulator();
    CPPUNIT_ASSERT_THROW(wa_dummy.mean(), NoDataException);
}


