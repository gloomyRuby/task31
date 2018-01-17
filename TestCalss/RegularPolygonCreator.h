//
// Created by Oysha on 17/01/2018.
//


#pragma once


#include "../Polygon.h"
#include <cmath>


class RegularPolygonCreator
{
    int countOfVertex;
    double radius;

public:
    RegularPolygonCreator(int n, double rad);
    Polygon &createRegularPolygon() const;
};
