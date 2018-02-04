//
// Created by Oysha on 02/01/2018.
//

#include <cmath>
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


NaiveTriangulationAlgorithm::NaiveTriangulationAlgorithm(const ChordExtractor &_chordExtractor)
        : chordExtractor(_chordExtractor)
{

}

Triangulation NaiveTriangulationAlgorithm::computeTriangulation(Polygon &p)
{
    const ChordMath chordMath(p);

    std::vector<Chord> result;

    std::vector<Chord> chords = chordExtractor.chordsFromPolygon(p);
    if (chords.empty()) {
        return Triangulation();
    }

    OptTriangulationLess less(p);
    std::sort(chords.begin(), chords.end(), less);

    int n = static_cast<int>(p.vertexCount()) - 3;
    result.push_back(chords[0]);

    int i = 1;
    while (i < chords.size() && result.size() < n) {
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
    }

    for (int k = 0; k < result.size(); ++k) {
        sum += chordMath.squaredLength(p, result[k]);
    }

    test = isChordCrossing(result, p);
    return result;
}

bool NaiveTriangulationAlgorithm::isChordCrossing(std::vector<Chord> result, Polygon &p)
{
    ChordMath chordMath(p);
    bool value = true;
    for (int i = 0; i < result.size() - 1; ++i) {
        for (int j = i + 1; j < result.size(); ++j) {
            if (chordMath.isCrossing(result[i], result[j]))
                value = false;
        }
    }
    return value;
}
