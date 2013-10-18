#include "SpinTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(SpinTest);

void SpinTest::setUp()
{
    up = Spin::Up;
    down = Spin::Down;
    m = 10L;
}


void SpinTest::tearDown() {}


void SpinTest::testNegation()
{
    CPPUNIT_ASSERT_EQUAL( - up, down);
    CPPUNIT_ASSERT_EQUAL( - down, up);
}


void SpinTest::testInternalMultiplication()
{
    CPPUNIT_ASSERT_EQUAL(up   * down, - 1);
    CPPUNIT_ASSERT_EQUAL(down * up,   - 1);
    CPPUNIT_ASSERT_EQUAL(up   * up,     1);
    CPPUNIT_ASSERT_EQUAL(down * down,   1);
}


void SpinTest::testInternalAddition()
{
    CPPUNIT_ASSERT_EQUAL(up   + down,   0);
    CPPUNIT_ASSERT_EQUAL(down + up,     0);
    CPPUNIT_ASSERT_EQUAL(up   + up,     2);
    CPPUNIT_ASSERT_EQUAL(down + down, - 2);
}


void SpinTest::testInternalSubtraction()
{
    CPPUNIT_ASSERT_EQUAL(up   - down,   2);
    CPPUNIT_ASSERT_EQUAL(down - up,   - 2);
    CPPUNIT_ASSERT_EQUAL(up   - up,     0);
    CPPUNIT_ASSERT_EQUAL(down - down,   0);
}


void SpinTest::testExternalMultiplication()
{
    CPPUNIT_ASSERT_EQUAL(m * up,     m);
    CPPUNIT_ASSERT_EQUAL(m * down, - m);
    CPPUNIT_ASSERT_EQUAL(m * down, down * m);
    CPPUNIT_ASSERT_EQUAL(m * up, up * m);
}


void SpinTest::testExternalAddition()
{
    CPPUNIT_ASSERT_EQUAL(m + up,   m + 1);
    CPPUNIT_ASSERT_EQUAL(m + down, m - 1);
    CPPUNIT_ASSERT_EQUAL(m + down, down + m);
    CPPUNIT_ASSERT_EQUAL(m + up, up + m);
}


void SpinTest::testExternalSubtraction()
{
    CPPUNIT_ASSERT_EQUAL(m - up,   m - 1);
    CPPUNIT_ASSERT_EQUAL(m - down, m + 1);
    CPPUNIT_ASSERT_EQUAL(m - down, - (down - m));
    CPPUNIT_ASSERT_EQUAL(m - up, - (up - m));
}

