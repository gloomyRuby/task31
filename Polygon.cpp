//
// Created by Oysha on 09/01/2018.
//

#include "Polygon.h"


Polygon::Polygon(const std::vector<Point> &_points) : points(_points)
{

}

size_t Polygon::numOfVertex() const
{
    return points.empty() ? 0 : points.size() - 1;
}

Point Polygon::getVertexAtIndex(const unsigned int index) const
{
    // should throw exception "index out of bounds"
    return points[index % points.size()];
}
