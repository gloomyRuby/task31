//
// Created by Oysha on 08/01/2018.
//

#include <cfloat>
#include "Point.h"


const Point Point::InvalidPoint = Point(DBL_MAX, DBL_MAX);


Point::Point(double _x, double _y) : x(_x), y(_y)
{

}
