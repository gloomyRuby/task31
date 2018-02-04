//
// Created by Oysha on 28/01/2018.
//


#pragma once

#include "../Polygon.h"
#include <cmath>


class RegularPolygon
{
public:
    Polygon createRegularPolygon(int n, double radius);
    double chordsSum(Polygon p);
};
