#include <iostream>
#include "PointsReader.h"
#include "Test/ChordExtractorTest.h"
#include "Test/AlgorithmTests.h"
#include "Test/PointsReaderTest.h"


int main()
{
    PointsReaderTest readerTest;
    readerTest.test();

    AlgorithmTests algorithmTests;
    algorithmTests.test();

    ChordExtractorTest chordExtractorTest;
    chordExtractorTest.test();

    return 0;
}