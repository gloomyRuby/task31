//
// Created by Oysha on 03/02/2018.
//

#include <cmath>
#include <cstdlib>
#include "PolygonInCircle.h"

int comp2 (const void * a, const void * b)
{
    return ( *(double*)b - *(double*)a );
};

Polygon PolygonInCircle::createPolygonInCircle(int n, double R)
{
    double mod = R;
    double arg = 0, phi = 0, array[10000];
    Point fisrdtAndLast(0, 0);

    std::vector<Point> tmpPolygon;

    srand(10);
    for (int i = 0; i < n; ++i) {
        arg = (int)(phi + rand() % 360) % 360;
        phi = arg;
        array[i] = arg;
    }
    qsort(array, n, sizeof(double), comp2);

    for (int i = 0; i < n; ++i) {
        double x = mod * cos(array[i] * 180 / M_PI);
        double y = mod * sin(array[i] * 180 / M_PI);
        tmpPolygon.push_back(Point(x, y));
        if (i == 0) {
            fisrdtAndLast.x = x;
            fisrdtAndLast.y = y;
        }
    }
    tmpPolygon.push_back(fisrdtAndLast);

    return Polygon(tmpPolygon);
}
