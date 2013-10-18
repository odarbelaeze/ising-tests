#ifndef SPIN_TEST_H_
#define SPIN_TEST_H_

#include "../src/SpinMath.h"

#include <cppunit/extensions/HelperMacros.h>

class SpinTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(SpinTest);
    CPPUNIT_TEST(testNegation);
    
    CPPUNIT_TEST(testInternalMultiplication);
    CPPUNIT_TEST(testInternalAddition);
    CPPUNIT_TEST(testInternalSubtraction);
    
    CPPUNIT_TEST(testExternalMultiplication);
    CPPUNIT_TEST(testExternalAddition);
    CPPUNIT_TEST(testExternalSubtraction);
    
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    
    void testNegation();
    
    void testInternalMultiplication();
    void testInternalAddition();
    void testInternalSubtraction();
    
    void testExternalMultiplication();
    void testExternalAddition();
    void testExternalSubtraction();

private:
    Spin up;
    Spin down;
    long m;

};

#endif