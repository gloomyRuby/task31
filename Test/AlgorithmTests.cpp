//
// Created by Oysha on 02/01/2018.
//

#include "AlgorithmTests.h"
#include "../NaiveTriangulationAlgorithm.h"
#include "Assert.h"


AlgorithmTests::AlgorithmTests(const FixtureFactory &_fixtureFactory)
        : fixtureFactory(_fixtureFactory)
{}


void AlgorithmTests::test() const
{
    testSquare();
    testQuad();
    testPentagon();
}

void AlgorithmTests::testSquare() const
{
    // sut - system under test
    NaiveTriangulationAlgorithm sut;

    // given
    Polygon p = fixtureFactory.createSquare();
    ChordMath chordMath = ChordMath(p);

    // when
    Triangulation t = sut.computeTriangulation(p);

    // then
    Assert::assertTrue(t.chords.size() == 1);

    Chord ch = t.chords[0];
    Assert::assertDoubleEqual(chordMath.squaredLength(p, ch), 2);
}

void AlgorithmTests::testQuad() const
{
    NaiveTriangulationAlgorithm sut;

    // given
    Polygon quad = fixtureFactory.createQuad();
    ChordMath chordMath = ChordMath(quad);

    // when
    Triangulation t = sut.computeTriangulation(quad);

    // then
    Assert::assertTrue(t.chords.size() == 1);

    Chord ch = t.chords[0];
    Assert::assertTrue(chordMath.squaredLength(quad, ch) <= SQR(6));
}

void AlgorithmTests::testPentagon() const
{
    NaiveTriangulationAlgorithm sut;

    // given
    Polygon pentagon = fixtureFactory.createPentagon();
    ChordMath chordMath = ChordMath(pentagon);

    // when
    Triangulation t = sut.computeTriangulation(pentagon);

    // then
    Assert::assertTrue(t.chords.size() == 2);

    Chord ch1 = t.chords[0];
    Chord ch2 = t.chords[1];
    Assert::assertTrue((chordMath.squaredLength(pentagon, ch1) + chordMath.squaredLength(pentagon, ch2)) <= SQR(16));
}
