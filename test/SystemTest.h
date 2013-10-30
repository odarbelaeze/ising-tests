#ifndef SYSTEM_TEST_H_
#define SYSTEM_TEST_H_

#include "../src/System.h"

#include <cppunit/extensions/HelperMacros.h>

class SystemTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(SystemTest);
    CPPUNIT_TEST_EXCEPTION(testConstructorThrows, InvalidParticleNumberException);
    CPPUNIT_TEST_EXCEPTION(testConstructorThrowsNegative, InvalidParticleNumberException);
    CPPUNIT_TEST_EXCEPTION(testSetThrowsUp, InvalidStateException);
    CPPUNIT_TEST_EXCEPTION(testSetThrowsDown, InvalidStateException);
    CPPUNIT_TEST(testSetOutput);
    CPPUNIT_TEST(testMagnetization);
    CPPUNIT_TEST(testEnergy);
    CPPUNIT_TEST(testWeights);
    CPPUNIT_TEST(testGetWeightThrows);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void testConstructorThrows();
    void testConstructorThrowsNegative();
    void testSetThrowsUp();
    void testSetThrowsDown();
    void testSetOutput();
    void testMagnetization();
    void testEnergy();
    void testWeights();
    void testGetWeightThrows();


private:
    System* sys;
    Spin up;
    Spin down;

};

#endif