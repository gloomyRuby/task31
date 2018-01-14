//
// Created by Oysha on 08/01/2018.
//

#include <cmath>
#include <cfloat>
#include "Point.h"


bool operator==(const Point &p1, const Point &p2)
{
    return fabs(p1.x - p2.x) < DBL_EPSILON
           && fabs(p1.y - p2.y) < DBL_EPSILON;
}


Point::Point(double x, double y, bool valid) : x(x), y(y), valid(valid)
{
}

bool Point::isValid() const
{
    return valid;
}
