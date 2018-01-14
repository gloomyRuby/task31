//
// Created by Oysha on 08/01/2018.
//


#pragma once


class Point
{
    bool valid;

public:
    double x, y;
    bool isValid() const;

    Point(double x, double y, bool valid = true);
};


bool operator==(const Point &p1, const Point &p2);
