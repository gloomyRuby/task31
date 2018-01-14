//
// Created by Oysha on 09/01/2018.
//


#pragma once


#include "Polygon.h"
#include "Chord.h"


class ChordMath
{
    Polygon polygon;
public:
    ChordMath(const Polygon &_polygon);

    // NOTE: returns InvalidPoint if ch1 and ch2 do not cross (i.e. are parallel)
    Point getPointOfCrossing(const Chord &ch1, const Chord &ch2) const;

    bool isPointInsidePolygon(const Polygon &p, const Point &a) const;
    bool isCrossing(const Chord &ch1, const Chord &ch2) const;
    virtual double squaredLength(const Polygon &polygon, const Chord &ch1) const;
};
