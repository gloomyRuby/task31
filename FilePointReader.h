//
// Created by Oysha on 15/01/2018.
//


#pragma once


#include <vector>
#include "Point.h"
#include "PointsReader.h"

class FilePointReader : public PointsReader
{
public:
    std::vector<Point> *pointsFromFile(std::string &filename) const;
};
