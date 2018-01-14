//
// Created by Oysha on 09/01/2018.
//

#include "Chord.h"


Chord::Chord(unsigned int _v1, unsigned int _v2) : v1(MIN(_v1, _v2)), v2(MAX(_v1, _v2))
{

}

unsigned int Chord::getBegin() const
{
    return v1;
}

unsigned int Chord::getEnd() const
{
    return v2;
}

bool Chord::isValid() const
{
    return ABS(v1 - v2) > 1;
}
