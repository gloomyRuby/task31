//
// Created by Oysha on 28/01/2018.
//

#include "RegularPolygon.h"
#include "../ChordExtractor.h"
#include "../ChordMath.h"


struct ChordLess
{
    const Polygon &polygon;
    ChordLess(const Polygon &polygon) : polygon(polygon) {}

    ChordMath chordMath = ChordMath(polygon);
    bool operator()(const Chord &x, const Chord &y)
    {
        return chordMath.squaredLength(polygon, x) < chordMath.squaredLength(polygon, y);
    }
};


Polygon RegularPolygon::createRegularPolygon(int n, double radius)
{
    double R = radius / cos(M_PI/n);
    double phi = M_PI / n;
    Point zero(0, 0);
    Point firstAndLast(0, 0);

    std::vector<Point> tmpPolygon;

    for (int i = 0; i < n; i++) {
        double x_i;
        double y_i;

        x_i = zero.x + R * cos((2 * M_PI * i)/n + phi);
        y_i = zero.y + R * sin((2 * M_PI * i)/n + phi);

        tmpPolygon.push_back(Point(x_i, y_i));
        if (i == 0) {
            firstAndLast = Point(x_i, y_i);
        }
    }
    tmpPolygon.push_back(firstAndLast);


    return Polygon(tmpPolygon);
}

double RegularPolygon::chordsSum(Polygon p)
{
    double sum = 0;
    ChordExtractor ch;
    std::vector<Chord> chords = ch.chordsFromPolygon(p);

    ChordLess less(p);
    std::sort(chords.begin(), chords.end(), less);

    ChordMath chordMath(p);
    int n = p.vertexCount();

    std::vector<Chord> result;
    int i = 1;
    result.push_back(chords[0]);
    sum = chordMath.squaredLength(p, result[0]);

    while (i < n - 3) {
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
        sum += chordMath.squaredLength(p, x);
    }

    return sum;
}
