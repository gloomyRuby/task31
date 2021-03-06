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
    double sum = 0;
    bool test;
    NaiveTriangulationAlgorithm(const ChordExtractor &chordExtractor = ChordExtractor());

    Triangulation computeTriangulation(Polygon &p);
    bool isChordCrossing(std::vector<Chord> result, Polygon &p);

private:
    const ChordExtractor chordExtractor;
};
