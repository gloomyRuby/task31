//
// Created by Oysha on 09/01/2018.
//

#include <cmath>
#include "Polygon.h"
#include "ChordMath.h"


//static const double DBL_DELTA = 0.00000000001;

ChordMath::ChordMath(const Polygon &_polygon) : polygon(_polygon)
{

}

Point ChordMath::getPointOfCrossing(const Chord &ch1, const Chord &ch2) const
{
    Point p1 = polygon.getVertexAtIndex(ch1.getBegin());
    Point p2 = polygon.getVertexAtIndex(ch1.getEnd());
    Point p3 = polygon.getVertexAtIndex(ch2.getBegin());
    Point p4 = polygon.getVertexAtIndex(ch2.getEnd());

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
        return Point::InvalidPoint;
    }

    double x;
    double y;
    x = ((x1*y2 - y1*x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4))/d;
    y = ((x1*y2 - y1*x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4))/d;

    return Point(x, y);
}

bool ChordMath::isPointInsidePolygon(const Polygon &p, const Point &a) const
{
    bool c = false;
    for (size_t i = 0, j = p.numOfVertex(); i < p.numOfVertex(); j = i++) {

        double dx = p.getVertexAtIndex(j).x - p.getVertexAtIndex(i).x;
        double dy_i = a.y - p.getVertexAtIndex(i).y;
        double dy_j = p.getVertexAtIndex(j).y - p.getVertexAtIndex(i).y;
        double delta = dx * dy_i / dy_j + p.getVertexAtIndex(i).x;
        bool isIntersectedWithY = (p.getVertexAtIndex(i).y <= a.y) && (a.y < p.getVertexAtIndex(j).y);
        bool isIntersectedWithY2 = (p.getVertexAtIndex(j).y <= a.y) && (a.y < p.getVertexAtIndex(i).y);

        if ((isIntersectedWithY || isIntersectedWithY2) && (a.x > delta)) {
            c = !c;
        }
    }
    return c;
}

bool ChordMath::isCrossing(const Chord &ch1, const Chord &ch2) const
{
    Point pointOfCrossing = getPointOfCrossing(ch1, ch2);
    return isPointInsidePolygon(polygon, pointOfCrossing);
}


double ChordMath::squaredLength(const Polygon &polygon, const Chord &ch) const
{
    Point p1 = polygon.getVertexAtIndex(ch.getBegin());
    Point p2 = polygon.getVertexAtIndex(ch.getEnd());
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}
