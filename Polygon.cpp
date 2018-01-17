//
// Created by Oysha on 09/01/2018.
//

#include "Polygon.h"


Polygon::Polygon() : points(0)
{

}

Polygon::Polygon(const std::vector<Point> &_points) : points(_points)
{

}

unsigned int Polygon::vertexCount() const
{
    return points.empty() ? 0 : points.size() - 1;
}

Point Polygon::vertexAtIndex(const unsigned int index) const
{
    // should throw exception "index out of bounds"
    return points[index % points.size()];
}
