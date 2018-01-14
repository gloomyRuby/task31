//
// Created by Oysha on 09/01/2018.
//

#include <fstream>
#include "PointsReader.h"


// 1. переделать на iostream
// 2. написать тестовый класс используя iostringstream
std::vector<Point> *PointsReader::getPoints(const char *filename)
{
    int n;
    double x, y;
    std::vector<Point> *points = new std::vector<Point>();

    std::fstream file;
    file.open(filename, std::fstream::in);

    file >> n;
    for (int i = 0; i < n; i++) {
        file >> x >> y;
        points->push_back(Point(x, y));
    }

    file.close();

    return points;
}
