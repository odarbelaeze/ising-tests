#include "SystemTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(SystemTest);

void SystemTest::setUp()
{
    up = Spin::Up;
    down = Spin::Down;
}


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


void SystemTest::testSetOutput()
{

    Spin state[] = {Spin::Up, Spin::Up, Spin::Down};
    sys = new System(3);
    sys -> set(4);
    /*
        Nothing really implemented here.
    */
}


void SystemTest::testMagnetization()
{
    sys = new System(10);
    sys -> set(0);
    CPPUNIT_ASSERT_EQUAL(- 10L, sys -> magnetization());
    sys -> set(1);
    CPPUNIT_ASSERT_EQUAL(- 8L, sys -> magnetization());
    sys -> set(1022);
    CPPUNIT_ASSERT_EQUAL(  8L, sys -> magnetization());
    sys -> set(666);
    CPPUNIT_ASSERT_EQUAL(  0L, sys -> magnetization());
}

void SystemTest::testEnergy()
{
    sys = new System(10);
    sys -> set(0);
    CPPUNIT_ASSERT_EQUAL( - 10L, sys -> energy());
    sys -> set(1);
    CPPUNIT_ASSERT_EQUAL( -  6L, sys -> energy());
    sys -> set(1022);
    CPPUNIT_ASSERT_EQUAL( -  6L, sys -> energy());
    sys -> set(666);
    CPPUNIT_ASSERT_EQUAL(    6L, sys -> energy());
}


void SystemTest::testWeights()
{
    sys = new System(10);
    sys -> setWeights(0.5);
    CPPUNIT_ASSERT_EQUAL(std::exp( - 10 / 0.5), sys -> getWeight(10));
    CPPUNIT_ASSERT_EQUAL(std::exp( - 20 / 0.5), sys -> getWeight(20));
    CPPUNIT_ASSERT_EQUAL(std::exp( + 10 / 0.5), sys -> getWeight(- 10));
    CPPUNIT_ASSERT_EQUAL(std::exp( + 20 / 0.5), sys -> getWeight(- 20));
}



void SystemTest::testGetWeightThrows()
{
    sys = new System(10);
    sys -> setWeights(0.5);
    CPPUNIT_ASSERT_THROW(sys -> getWeight(21), UnavailableEnergyException);
    CPPUNIT_ASSERT_THROW(sys -> getWeight(-21), UnavailableEnergyException);
}
