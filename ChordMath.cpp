//
// Created by Oysha on 09/01/2018.
//

#include <cmath>
#include "Polygon.h"
#include "ChordMath.h"


ChordMath::ChordMath(const Polygon &_polygon) : polygon(_polygon)
{

}

Point ChordMath::getPointOfCrossing(const Chord &ch1, const Chord &ch2) const
{
    Point p1 = polygon.vertexAtIndex(ch1.getBegin());
    Point p2 = polygon.vertexAtIndex(ch1.getEnd());
    Point p3 = polygon.vertexAtIndex(ch2.getBegin());
    Point p4 = polygon.vertexAtIndex(ch2.getEnd());

    double x1 = p1.x;
    double y1 = p1.y;
    double x2 = p2.x;
    double y2 = p2.y;
    double x3 = p3.x;
    double y3 = p3.y;
    double x4 = p4.x;
    double y4 = p4.y;
    double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

// if d == 0  => they do not cross. what should it return?
    if (fabs(d) <= 1) {
        return Point(0, 0, false);
    }

    double x;
    double y;
    x = ((x1*y2 - y1*x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4))/d;
    y = ((x1*y2 - y1*x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4))/d;

    return Point(x, y);
}

bool ChordMath::isPointInsidePolygon(const Point &p) const
{
    const unsigned int n = polygon.vertexCount();

    int c = 0;
    for (size_t i = 0, j = n - 1; i < n; j = i++) {

        double x = p.x;
        double y = p.y;
        double xp_i = polygon.vertexAtIndex(i).x;
        double xp_j = polygon.vertexAtIndex(j).x;
        double yp_i = polygon.vertexAtIndex(i).y;
        double yp_j = polygon.vertexAtIndex(j).y;

        if ((((yp_i <= y) && (y < yp_j)) || ((yp_j <= y) && (y < yp_i)))
            && (x > (xp_j - xp_i) * (y - yp_i) / (yp_j - yp_i) + xp_i))
        {
            c++;
        }
    }

    return c % 2 == 1;
}

bool ChordMath::isCrossing(const Chord &ch1, const Chord &ch2) const
{
    Point p = getPointOfCrossing(ch1, ch2);
    if (p.isValid()) {
        return isPointInsidePolygon(p) && !isPointEqualToPolygonVertex(p);
    }
    return false;
}

bool ChordMath::isPointEqualToPolygonVertex(const Point &p) const
{
    for (int i = 0; i < polygon.vertexCount(); ++i) {
        Point q = polygon.vertexAtIndex(i);
        if (p == q) {
            return true;
        }
    }
    return false;
}

double ChordMath::squaredLength(const Polygon &polygon, const Chord &ch) const
{
    Point p1 = polygon.vertexAtIndex(ch.getBegin());
    Point p2 = polygon.vertexAtIndex(ch.getEnd());
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}
