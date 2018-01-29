//
// Created by Oysha on 28/01/2018.
//

#include <iostream>
#include "Test.h"
#include "RegularPolygon.h"
#include "../NaiveTriangulationAlgorithm.h"
#include <ctime>


void Test::test() const
{
    std::cout.precision(3);
    std::cout << "N\tStep\tTime\t\tT/S\t\tT/A" << std::endl;

    RegularPolygon testPolygon;
    double time;
    for (int i = 700; i < 1600; i += 200) {
        double start = clock();
        double A = i * i;
        Polygon p = testPolygon.createRegularPolygon(i, 6);
        NaiveTriangulationAlgorithm triangulationAlgorithm;
        triangulationAlgorithm.computeTriangulation(p);
        double end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        int step = triangulationAlgorithm.step;
        double timePerStep = (double)time / step;
        double timePerA = time / A;

        std::cout << i << "\t" << step << "\t" << time << "\t\t" << timePerStep << "\t" << timePerA << "\n";
    }

}
