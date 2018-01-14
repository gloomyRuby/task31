//
// Created by Oysha on 09/01/2018.
//


#pragma once


#include <vector>
#include "Point.h"


class Polygon
{
    const std::vector<Point> points;
public:
    Polygon(const std::vector<Point> &_points);
    size_t numOfVertex() const;
    Point getVertexAtIndex(const unsigned int index) const;
};
