#include "SystemTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(SystemTest);

void SystemTest::setUp() {}
void SystemTest::tearDown() {}

void SystemTest::testConstructorThrows()
{
    sys = new System(0);
}


void SystemTest::testConstructorThrowsNegative()
{
    sys = new System( - 1);
}


void SystemTest::testSetThrowsUp()
{
    sys = new System(3);
    sys -> set(8);
}


void SystemTest::testSetThrowsDown()
{
    sys = new System(3);
    sys -> set(- 1);
}
