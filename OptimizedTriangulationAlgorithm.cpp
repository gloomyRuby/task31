//
// Created by Oysha on 04/02/2018.
//

#include <cmath>
#include <iostream>
#include "OptimizedTriangulationAlgorithm.h"
#include "NaiveTriangulationAlgorithm.h"


struct OptTriangulationLess
{
    const Polygon &polygon;
    OptTriangulationLess(const Polygon &polygon) : polygon(polygon) {}

    ChordMath chordMath = ChordMath(polygon);
    bool operator()(const Chord &x, const Chord &y)
    {
        return chordMath.squaredLength(polygon, x) < chordMath.squaredLength(polygon, y);
    }
};


OptimizedTriangulationAlgorithm::OptimizedTriangulationAlgorithm(const ChordExtractor &_chordExtractor)
        : chordExtractor(_chordExtractor)
{

}

Triangulation OptimizedTriangulationAlgorithm::computeTriangulation(Polygon &p)
{
    double minSum = INT32_MAX;
    const ChordMath chordMath(p);


    std::vector<Chord> chords = chordExtractor.chordsFromPolygon(p);
    if (chords.empty()) {
        return Triangulation();
    }

    OptTriangulationLess less(p);
    std::sort(chords.begin(), chords.end(), less);

    int n = static_cast<int>(p.vertexCount()) - 3;

    std::vector<Chord> finalResult;
    for (int l = 0; l < chords.size() - n; ++l) {
        std::vector<Chord> result;
        result.push_back(chords[l]);

        int i = 0;
        while (i < chords.size() && result.size() < n) {
            if (i != l) {
                Chord x = chords[i];
                bool isSuitable = true;
                for (int j = 0; j < result.size(); j++) {
                    if (chordMath.isCrossing(x, result[j])) {
                        isSuitable = false;
                        break;
                    }
                }
                if (isSuitable) {
                    result.push_back(x);
                }
                i++;
            } else {
                i++;
            }
        }
        sum = 0;
        for (int k = 0; k < result.size(); ++k) {
            sum += chordMath.squaredLength(p, result[k]);
        }
        if (sum < minSum && result.size() == n) {
            minSum = sum;
            finalResult = result;
        }
    }

    sum = minSum;
    test = isChordCrossing(finalResult, p);
    return finalResult;
}

bool OptimizedTriangulationAlgorithm::isChordCrossing(std::vector<Chord> result, Polygon &p)
{
    ChordMath chordMath(p);
    bool value = true;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = i + 1; j < result.size(); ++j) {
            if (chordMath.isCrossing(result[i], result[j]))
                value = false;
        }
    }
    return value;
}
