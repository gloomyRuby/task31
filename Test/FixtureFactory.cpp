//
// Created by Oysha on 11/01/2018.
//

#include "FixtureFactory.h"
//
// Created by Oysha on 03/01/2018.
//


Polygon FixtureFactory::createSquare() const
{
    std::vector<Point> points;
    points.push_back(Point(0, 0));
    points.push_back(Point(1, 0));
    points.push_back(Point(1, 1));
    points.push_back(Point(0, 1));
    points.push_back(Point(0, 0));
    return Polygon(points);
}

Polygon FixtureFactory::createQuad() const
{
    std::vector<Point> points;
    points.push_back(Point(0, 0));
    points.push_back(Point(8, 0));
    points.push_back(Point(8, 1));
    points.push_back(Point(6, 5));
    points.push_back(Point(0, 0));
    return Polygon(points);
}

Polygon FixtureFactory::createPentagon() const
{
    std::vector<Point> points;
    points.push_back(Point(0, 0));
    points.push_back(Point(8, 0));
    points.push_back(Point(8, 2));
    points.push_back(Point(4, 5));
    points.push_back(Point(0, 5));
    points.push_back(Point(0, 0));
    return Polygon(points);
}
