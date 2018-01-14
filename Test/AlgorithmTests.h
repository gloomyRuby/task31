//
// Created by Oysha on 02/01/2018.
//


#pragma once


#include <vector>
#include "../Point.h"
#include "FixtureFactory.h"
#include "../ChordMath.h"

#define SQR(x) ((x)*(x))


class AlgorithmTests
{
public:
    AlgorithmTests(const FixtureFactory &fixtureFactory = FixtureFactory());

    void test() const;

private:
    const FixtureFactory fixtureFactory;

    void testSquare() const;
    void testQuad() const;
    void testPentagon() const;
};
