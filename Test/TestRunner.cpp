//
// Created by Oysha on 14/01/2018.
//

#include "TestRunner.h"
#include "PointsReaderTest.h"
#include "AlgorithmTests.h"
#include "ChordExtractorTest.h"
#include "ChordTest.h"


void TestRunner::runTests() const
{
    PointsReaderTest readerTest;
    readerTest.test();

    AlgorithmTests algorithmTests;
    algorithmTests.test();

    ChordExtractorTest chordExtractorTest;
    chordExtractorTest.test();

    ChordTest chordTest;
    chordTest.test();
}