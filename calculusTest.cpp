#include <iostream>
#include <cmath>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>


#include "calculus.h"

const double EPSILON = 0.001; // maximum difference between the expected result and returned result
const double PI_TEST = 3.14159265359;

struct TestStruct
{
    std::string testName;
    bool result;
    bool expected;
    std::string errorMsg;
};

bool isClose(double a, double b)
{
    return fabs(a - b) <= EPSILON;
}

void runTestLoop(TestStruct testCases[], int testSize){
    int i;
    for (i = 0; i< testSize; i++){
        std::cout << testCases[i].testName + ": ";
        if (testCases[i].result == testCases[i].expected)
        {
            std::cout << "PASSED \n";
        }
        else
        {
            std::cout << testCases[i].errorMsg;
            exit(1);
        }
    }
}

class Test: public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testSum);
  CPPUNIT_TEST(successTestExit);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:
    
  void testSum() {
    int testSize = 2;
    TestStruct sumTestCases[testSize] = {
        {
            "test 1",
            isClose(mySum(2+3),5),
            true,
            "2 + 3 = 5"
        },
        {
            "test 2,
            isClose(mySum(2+4),6),
            true,
            "2 + 4 = 6"
        }
    }
  }

  void successTestExit(void){
    std::cout << "all tests passed! \n";
    exit(0);
  }

};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()
{
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}
