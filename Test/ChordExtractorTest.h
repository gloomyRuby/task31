//
// Created by Oysha on 03/01/2018.
//


#pragma once


#include "FixtureFactory.h"


class ChordExtractorTest
{
public:
    ChordExtractorTest(const FixtureFactory &fixtureFactory = FixtureFactory());

    void test() const;

private:
    const FixtureFactory fixtureFactory;

    void testSquare() const;
    void testPentagon() const;
};
