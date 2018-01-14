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
    NaiveTriangulationAlgorithm(const ChordExtractor &chordExtractor = ChordExtractor());

    Triangulation computeTriangulation(const Polygon &p) const;

private:
    const ChordExtractor chordExtractor;
};
