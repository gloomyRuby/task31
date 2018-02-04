#include "Test/TestRunner.h"
#include "Test/RegularPolygonTest.h"
#include "TestClass/Test.h"

long long int STEP = 0;

int main()
{
    Test test;
//    test.RandomTest(10, 60, 10);
    test.RegularTest(4, 10, 1);
    return 0;
}

