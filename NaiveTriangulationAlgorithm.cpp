//
// Created by Oysha on 02/01/2018.
//

#include "NaiveTriangulationAlgorithm.h"


struct NaiveTriangulationLess
{
    const Polygon &polygon;
    NaiveTriangulationLess(const Polygon &polygon) : polygon(polygon) {}

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

    NaiveTriangulationLess less(p);
    std::sort(chords.begin(), chords.end(), less);

    int n = static_cast<int>(p.vertexCount()) - 3;
    result.push_back(chords[0]);

    int i = 1;
    while (i < chords.size() && result.size() < n) {
        Chord x = chords[i];
        bool isSuitable = true;
        for (int j = 0; j < result.size(); j++) {
            step++;
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

    return result;
}
