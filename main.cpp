#include "Test/TestRunner.h"
#include "Test/RegularPolygonTest.h"
#include "TestClass/Test.h"

long long int STEP = 0;

int main()
{
    Test test;
//    test.RandomTest(50, 100, 10);
    test.RegularTest(10, 50, 10);
    return 0;
}

