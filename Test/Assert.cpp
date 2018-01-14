//
// Created by Oysha on 02/01/2018.
//

#include "Assert.h"
#include <cmath>


void Assert::assertTrue(const bool expression)
{
    if (!expression) {
        throw Failure();
    }
}

void Assert::assertDoubleEqual(const double d1, const double d2)
{
    if (fabs(d1 - d2) >= 0.00000000001) {
        throw Failure();
    }
}
