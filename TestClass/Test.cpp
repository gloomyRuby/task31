//
// Created by Oysha on 28/01/2018.
//

#include <iostream>
#include "Test.h"
#include "RegularPolygon.h"
#include "../NaiveTriangulationAlgorithm.h"
#include "PolygonInCircle.h"
#include "../Test/Assert.h"
#include "../OptimizedTriangulationAlgorithm.h"
#include <ctime>

extern long long int STEP;


void Test::RandomTest(int start, int end, int diff) const
{
    std::cout << "\nRandom Polygon Test\n" << std::endl;
    naivePolygonInCircleTest(start, end, diff);
    oprimizedPolygonInCircleTest(start, end, diff);
}

void Test::RegularTest(int start, int end, int diff) const
{
    std::cout << "\nRegular Polygon Test\n" << std::endl;
    naiveRegularTest(start, end, diff);
    optimizedRegularTest(start, end, diff);
}

void Test::naiveRegularTest(int start, int end, int diff) const
{
    std::cout.precision(3);
    std::cout << "Non optimized version\n";
    std::cout << "N\tStep\tTime\t\tT/S\t\t\tT/A\t\t\tSum" << std::endl;

    RegularPolygon testPolygon;
    double time;
    for (int i = start; i <= end; i += diff) {
        double k = i;
        double A = k * k * k * log(k);

        Polygon p = testPolygon.createRegularPolygon(i, 6);
        double testSum = testPolygon.chordsSum(p);
        NaiveTriangulationAlgorithm naiveAlgorithm;

        double start = clock();
        naiveAlgorithm.computeTriangulation(p);
        double end = clock();
        Assert::assertTrue(naiveAlgorithm.test);


        time = (double)(end - start) / CLOCKS_PER_SEC;
        long long int step = STEP;
        double timePerStep = (double)time / step;
        double timePerA = time / A;
        double sum = naiveAlgorithm.sum;

        std::cout << i << "\t" << step << "\t" << time << "\t\t" << timePerStep << "\t" << timePerA << "\t\t" << sum << "\n";
        STEP = 0;
    }
}

void Test::optimizedRegularTest(int start, int end, int diff) const
{
    std::cout.precision(3);
    std::cout << std::endl;
    std::cout << "Optimized version\n";
    std::cout << "N\tStep\tTime\t\tT/S\t\t\tT/A\t\tSum" << std::endl;

    RegularPolygon testPolygon;
    double time;
    for (int i = start; i <= end; i += diff) {
        double k = i;
        double A = k * k * k * log(k);

        Polygon p = testPolygon.createRegularPolygon(i, 6);
        double testSum = testPolygon.chordsSum(p);
        OptimizedTriangulationAlgorithm optimizedAlgorithm;

        double start = clock();
        optimizedAlgorithm.computeTriangulation(p);
        double end = clock();
        Assert::assertTrue(optimizedAlgorithm.test);

        time = (double)(end - start) / CLOCKS_PER_SEC;
        long long int step = STEP;
        double timePerStep = (double)time / step;
        double timePerA = time / A;
        double sum = optimizedAlgorithm.sum;

        std::cout << i << "\t" << step << "\t" << time << "\t\t" << timePerStep << "\t" << timePerA << "\t\t" << sum << "\n";
        STEP = 0;
    }
}

void Test::naivePolygonInCircleTest(int start, int end, int diff) const
{
    std::cout.precision(3);
    std::cout << "Non optimized version" << std::endl;
    std::cout << "N\tStep\tTime\t\tT/S\t\tT/A\t\t\t\tSum" << std::endl;

    PolygonInCircle testPolygon;
    double time;

    for (int i = start; i < end; i += diff) {
        double k = i;
        double A = k * k * k * log(k);

        Polygon p = testPolygon.createPolygonInCircle(i, 6);
        NaiveTriangulationAlgorithm naiveAlgorithm;

        double start = clock();
        naiveAlgorithm.computeTriangulation(p);
        double end = clock();

//        Assert::assertTrue(naiveAlgorithm.test);

        time = (double)(end - start) / CLOCKS_PER_SEC;
        long long int step = STEP;
        double timePerStep = (double)time / step;
        double timePerA = time / A;
        double sum = naiveAlgorithm.sum;

        std::cout << i << "\t" << step << "\t" << time << "\t\t" << timePerStep << "\t" << timePerA << "\t\t" << sum << "\n";
        STEP = 0;
    }
}

void Test::oprimizedPolygonInCircleTest(int start, int end, int diff) const
{
    std::cout.precision(3);
    std::cout << std::endl;
    std::cout << "Optimized version" << std::endl;
    std::cout << "N\tStep\tTime\t\tT/S\t\tT/A\t\t\t\tSum" << std::endl;

    PolygonInCircle testPolygon;
    double time;

    for (int i = start; i < end; i += diff) {
        double k = i;
        double A = k * k * k * log(k);

        Polygon p = testPolygon.createPolygonInCircle(i, 6);
        OptimizedTriangulationAlgorithm optimizedAlgorithm;

        double start = clock();
        optimizedAlgorithm.computeTriangulation(p);
        double end = clock();

//        Assert::assertTrue(optimizedAlgorithm.test);

        time = (double)(end - start) / CLOCKS_PER_SEC;
        long long int step = STEP;
        double timePerStep = (double)time / step;
        double timePerA = time / A;
        double sum = optimizedAlgorithm.sum;

        std::cout << i << "\t" << step << "\t" << time << "\t\t" << timePerStep << "\t" << timePerA << "\t\t" << sum << "\n";
        STEP = 0;
    }
}
