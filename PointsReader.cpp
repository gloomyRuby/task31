//
// Created by Oysha on 09/01/2018.
//

#include "PointsReader.h"


// 1. переделать на iostream
// 2. написать тестовый класс используя iostringstream
std::vector<Point> *PointsReader::getPoints(const char *filename)
{
    int n;
    double x, y;
    std::vector<Point> *points = new std::vector<Point>();

    FILE *file = fopen(filename, "r");

    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%lf %lf", &x, &y);
        points->push_back(Point(x, y));
    }

    fclose(file);

    return points;
}
