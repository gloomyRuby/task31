//
// Created by Oysha on 03/01/2018.
//

#include "ChordExtractorTest.h"
#include "../ChordExtractor.h"
#include "Assert.h"


ChordExtractorTest::ChordExtractorTest(const FixtureFactory &_fixtureFactory)
        : fixtureFactory(_fixtureFactory)
{}

void ChordExtractorTest::test() const
{
    testSquare();
    testPentagon();
}

void ChordExtractorTest::testSquare() const
{
    ChordExtractor sut;

    // given
    Polygon square = fixtureFactory.createSquare();

    // when
    std::vector<Chord> chords = sut.chordsFromPolygon(square);

    // then
    Assert::assertTrue(chords.size() == 2);
    Chord ch1 = chords[0];
    Chord ch2 = chords[1];
    Assert::assertTrue(ch1 == Chord(0, 2));
    Assert::assertTrue(ch2 == Chord(1, 3));
}

void ChordExtractorTest::testPentagon() const
{
    ChordExtractor sut;

    // given
    Polygon pentagon = fixtureFactory.createPentagon();

    // when
    std::vector<Chord> chords = sut.chordsFromPolygon(pentagon);

    // then
    Assert::assertTrue(chords.size() == 5);
    Assert::assertTrue(chords[0] == Chord(0, 2));
    Assert::assertTrue(chords[1] == Chord(0, 3));
    Assert::assertTrue(chords[2] == Chord(1, 3));
    Assert::assertTrue(chords[3] == Chord(1, 4));
    Assert::assertTrue(chords[4] == Chord(2, 4));
}
