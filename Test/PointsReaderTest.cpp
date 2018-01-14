//
// Created by Oysha on 02/01/2018.
//

#include <string>
#include <sstream>
#include <vector>
#include "PointsReaderTest.h"
#include "Assert.h"
#include "../PointsReader.h"


void PointsReaderTest::test()
{
    testSimple();
    testReadSquare();
}

void PointsReaderTest::testSimple() const
{
    PointsReader sut;

    // given
//    std::string data("2\n1 1\n2 2");
//    std::istringstream input(data);

    // when
    std::vector<Point> *points = sut.getPoints("input.txt");

    // then
    Assert::assertTrue(points->size() == 2);
    Assert::assertTrue(points->at(0) == Point(1, 1));
    Assert::assertTrue(points->at(1) == Point(2, 2));
}

void PointsReaderTest::testReadSquare()
{
    PointsReader sut;

    // given
//    std::string data("5\n0 0\n1 0\n1 1\n0 1\n0 0");
//    std::istringstream input(data);

    // when
    std::vector<Point> *points = sut.getPoints("square.txt");

    // then
    Assert::assertTrue(points->size() == 5);
    Assert::assertTrue(points->at(0) == Point(0, 0));
    Assert::assertTrue(points->at(1) == Point(1, 0));
    Assert::assertTrue(points->at(2) == Point(1, 1));
    Assert::assertTrue(points->at(3) == Point(0, 1));
    Assert::assertTrue(points->at(4) == Point(0, 0));
}
