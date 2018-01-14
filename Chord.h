//
// Created by Oysha on 09/01/2018.
//


#pragma once

#include "Point.h"
#include "Polygon.h"


#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : -(a))


class Chord
{
    unsigned int v1, v2;
public:
    Chord(unsigned int _v1, unsigned int _v2);
    unsigned int getBegin() const;
    unsigned int getEnd() const;
    bool isValid() const;
};

inline bool operator==(const Chord &ch1, const Chord &ch2)
{
    return ((ch1.getBegin() == ch2.getBegin() && ch1.getEnd() == ch2.getEnd())
            || (ch1.getBegin() == ch2.getEnd() && ch1.getEnd() == ch2.getBegin()));
}
