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
    unsigned int vertexCount() const;
    Point vertexAtIndex(const unsigned int index) const;
};
