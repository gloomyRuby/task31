//
// Created by Oysha on 17/01/2018.
//

#include "RegularPolygonCreator.h"


RegularPolygonCreator::RegularPolygonCreator(int n, double rad) : countOfVertex(n), radius(rad)
{
}

Polygon &RegularPolygonCreator::createRegularPolygon() const
{
    int n = countOfVertex;
    double R = radius / cos(M_PI/n);
    double phi = M_PI / n;
    Point zero(0, 0);
    Point firstAndLast(0, 0);

    std::vector<Point> tmpPolygon;
    Polygon regularPolygon;

    for (int i = 0; i < n - 1; i++) {
        double x_i;
        double y_i;

        x_i = zero.x + R * cos((2 * M_PI * i)/n + phi);
        y_i = zero.y + R * sin((2 * M_PI * i)/n + phi);

        tmpPolygon.push_back(Point(x_i, y_i));
        if (i == 0) {
            firstAndLast = Point(x_i, y_i);
        }
    }

    tmpPolygon.push_back(firstAndLast);

    regularPolygon = tmpPolygon;

    return regularPolygon;
}
