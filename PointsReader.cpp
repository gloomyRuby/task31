//
// Created by Oysha on 09/01/2018.
//

#include <fstream>
#include "PointsReader.h"


// 1. переделать на iostream
// 2. написать тестовый класс используя iostringstream
std::vector<Point> * PointsReader::getPoints(std::istream &input) const
{
    int n;
    double x, y;
    std::vector<Point> *points = new std::vector<Point>();

    input >> n;
    for (int i = 0; i < n; i++) {
        input >> x >> y;
        points->push_back(Point(x, y));
    }

    return points;
}
