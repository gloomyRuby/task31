//
// Created by Oysha on 09/01/2018.
//


#pragma once


#include <vector>
#include "Point.h"


class PointsReader
{
public:
    std::vector<Point> *getPoints(const char *filename);
};
