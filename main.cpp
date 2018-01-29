#include "Test/TestRunner.h"
#include "Test/RegularPolygonTest.h"
#include "TestClass/Test.h"


int main()
{
    TestRunner runner;
    runner.runTests();

//    RegularPolygonTest regularPolygonTest;
//    regularPolygonTest.test();
    Test test;
    test.test();
    return 0;
}

