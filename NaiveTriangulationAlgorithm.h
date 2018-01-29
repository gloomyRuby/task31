//
// Created by Oysha on 02/01/2018.
//

#pragma once


#include "TriangulationAlgorithm.h"
#include "ChordExtractor.h"
#include "ChordMath.h"


class NaiveTriangulationAlgorithm : TriangulationAlgorithm
{
public:
    int step = 0;
    NaiveTriangulationAlgorithm(const ChordExtractor &chordExtractor = ChordExtractor());

    Triangulation computeTriangulation(Polygon &p);

private:
    const ChordExtractor chordExtractor;
};
