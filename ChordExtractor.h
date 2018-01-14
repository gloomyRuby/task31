//
// Created by Oysha on 12/01/2018.
//


#pragma once


#include "Polygon.h"
#include "Chord.h"


class ChordExtractor
{
public:
    // each chord is added to result only once
    virtual std::vector<Chord> chordsFromPolygon(const Polygon &p) const;
};
