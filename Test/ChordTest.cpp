//
// Created by Oysha on 11/01/2018.
//

#include "ChordTest.h"
#include "../Chord.h"
#include "../ChordMath.h"
//#include "../../Algorithm/NaiveTriangulationAlgorithm.h"
#include "Assert.h"

void ChordTest::test() const
{
    testIsCrossing();
}

ChordTest::ChordTest(const FixtureFactory &_fixtureFactory)
        : fixtureFactory(_fixtureFactory)
{}

void ChordTest::testIsCrossing() const
{
    // given
    Polygon pentagon = fixtureFactory.createPentagon();

    ChordMath chordMath(pentagon);
    Chord x1(0, 2);
    Chord x2(0, 3);
    Chord x3(1, 3);
    Chord x4(1, 4);
    Chord x5(2, 4);

    // when
    Assert::assertTrue(!chordMath.isCrossing(x1, x2));
    Assert::assertTrue(chordMath.isCrossing(x1, x3));
    Assert::assertTrue(chordMath.isCrossing(x1, x4));
    Assert::assertTrue(!chordMath.isCrossing(x1, x5));
    Assert::assertTrue(!chordMath.isCrossing(x2, x3));
    Assert::assertTrue(chordMath.isCrossing(x2, x4));
    Assert::assertTrue(chordMath.isCrossing(x2, x5));
    Assert::assertTrue(!chordMath.isCrossing(x3, x4));
    Assert::assertTrue(chordMath.isCrossing(x3, x5));
    Assert::assertTrue(!chordMath.isCrossing(x4, x5));
}
