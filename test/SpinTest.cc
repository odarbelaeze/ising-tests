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
    CPPUNIT_ASSERT_EQUAL(down,  - up);
    CPPUNIT_ASSERT_EQUAL(up,  - down);
}


void SpinTest::testInternalMultiplication()
{
    CPPUNIT_ASSERT_EQUAL( - 1, up   * down);
    CPPUNIT_ASSERT_EQUAL( - 1, down * up);
    CPPUNIT_ASSERT_EQUAL(   1, up   * up);
    CPPUNIT_ASSERT_EQUAL(   1, down * down);
}


void SpinTest::testInternalAddition()
{
    CPPUNIT_ASSERT_EQUAL(   0, up   + down);
    CPPUNIT_ASSERT_EQUAL(   0, down + up);
    CPPUNIT_ASSERT_EQUAL(   2, up   + up);
    CPPUNIT_ASSERT_EQUAL( - 2, down + down);
}


void SpinTest::testInternalSubtraction()
{
    CPPUNIT_ASSERT_EQUAL(   2, up   - down);
    CPPUNIT_ASSERT_EQUAL( - 2, down - up);
    CPPUNIT_ASSERT_EQUAL(   0, up   - up);
    CPPUNIT_ASSERT_EQUAL(   0, down - down);
}


void SpinTest::testExternalMultiplication()
{
    CPPUNIT_ASSERT_EQUAL(m, m * up);
    CPPUNIT_ASSERT_EQUAL( - m, m * down);
    CPPUNIT_ASSERT_EQUAL(m * down, down * m);
    CPPUNIT_ASSERT_EQUAL(m * up, up * m);
}


void SpinTest::testExternalAddition()
{
    CPPUNIT_ASSERT_EQUAL(m + 1,   m + up);
    CPPUNIT_ASSERT_EQUAL(m - 1, m + down);
    CPPUNIT_ASSERT_EQUAL(m + down, down + m);
    CPPUNIT_ASSERT_EQUAL(m + up, up + m);
}


void SpinTest::testExternalSubtraction()
{
    CPPUNIT_ASSERT_EQUAL(m - 1, m - up);
    CPPUNIT_ASSERT_EQUAL(m + 1, m - down);
    CPPUNIT_ASSERT_EQUAL( - (down - m), m - down);
    CPPUNIT_ASSERT_EQUAL( - (up - m), m - up);
}

