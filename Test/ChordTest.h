//
// Created by Oysha on 11/01/2018.
//


#pragma once
//
// Created by Oysha on 03/01/2018.
//


#include "FixtureFactory.h"
#include "../ChordMath.h"


class ChordTest
{
public:
    void test() const;

    ChordTest(const FixtureFactory &fixtureFactory = FixtureFactory());

private:
    void testIsCrossing() const;

    const FixtureFactory fixtureFactory;
};
