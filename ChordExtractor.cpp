//
// Created by Oysha on 12/01/2018.
//

#include "ChordExtractor.h"


std::vector<Chord> ChordExtractor::chordsFromPolygon(const Polygon &p) const
{
    std::vector<Chord> result;

    int n = static_cast<int>(p.vertexCount());

    for (int i = 2; i < n - 1; i++) {
        result.push_back(Chord(0, i));
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 2; j <= n - 1; j++) {
            result.push_back(Chord(i, j));
        }
    }

    return result;
}
