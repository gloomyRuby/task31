//
// Created by Oysha on 08/01/2018.
//


#pragma once


struct Point
{
    static const Point InvalidPoint;
    double x, y;
    Point(double _x, double _y);
};

inline bool operator==(const Point &p1, const Point &p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}
