//
// Created by Oysha on 08/01/2018.
//

#include <cmath>
#include <cfloat>
#include "Point.h"

// DBL_EPSILON

bool operator==(const Point &p1, const Point &p2)
{
    return fabs(p1.x - p2.x) < 0.000001
           && fabs(p1.y - p2.y) < 0.000001;
}


Point::Point(double x, double y, bool valid) : x(x), y(y), valid(valid)
{
}

bool Point::isValid() const
{
    return valid;
}
