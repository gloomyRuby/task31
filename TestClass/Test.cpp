//
// Created by Oysha on 28/01/2018.
//

#include <iostream>
#include "Test.h"
#include "RegularPolygon.h"
#include "../NaiveTriangulationAlgorithm.h"
#include "PolygonInCircle.h"
#include <ctime>


void Test::RegularPolygonTest() const
{
    std::cout.precision(3);
    std::cout << "N\tStep\tTime\t\tT/S\t\tT/A" << std::endl;

    RegularPolygon testPolygon;
    double time;
    for (int i = 100; i < 180; i += 10) {
        double A = i * i * log(i);

        Polygon p = testPolygon.createRegularPolygon(i, 6);
        NaiveTriangulationAlgorithm triangulationAlgorithm;

        double start = clock();
        triangulationAlgorithm.computeTriangulation(p);
        double end = clock();

        time = (double)(end - start) / CLOCKS_PER_SEC;
        int step = triangulationAlgorithm.step;
        double timePerStep = (double)time / step;
        double timePerA = time / A;

        std::cout << i << "\t" << step << "\t" << time << "\t\t" << timePerStep << "\t" << timePerA << "\n";
    }
}

void Test::PolygonInCircleTest() const
{
    std::cout.precision(3);
    std::cout << "N\tStep\tTime\t\tT/S\t\tT/A" << std::endl;

    PolygonInCircle testPolygon;
    double time;

    for (int i = 50; i < 100; i += 10) {
        double A = i * i * log(i);

        Polygon p = testPolygon.createPolygonInCircle(i, 8);
        NaiveTriangulationAlgorithm triangulationAlgorithm;

        double start = clock();
        triangulationAlgorithm.computeTriangulation(p);
        double end = clock();

        time = (double)(end - start) / CLOCKS_PER_SEC;
        int step = triangulationAlgorithm.step;
        double timePerStep = (double)time / step;
        double timePerA = time / A;

        std::cout << i << "\t" << step << "\t" << time << "\t\t" << timePerStep << "\t" << timePerA << "\n";
    }
}

void Test::test() const
{

}
