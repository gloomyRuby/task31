//
// Created by Oysha on 04/02/2018.
//
#include "TriangulationAlgorithm.h"
#include "ChordExtractor.h"
#include "ChordMath.h"



#pragma once


class OptimizedTriangulationAlgorithm : TriangulationAlgorithm
{
public:
    double sum = 0;
    bool test;
    OptimizedTriangulationAlgorithm(const ChordExtractor &chordExtractor = ChordExtractor());

    Triangulation computeTriangulation(Polygon &p);
    bool isChordCrossing(std::vector<Chord> result, Polygon &p);

private:
    const ChordExtractor chordExtractor;
};
