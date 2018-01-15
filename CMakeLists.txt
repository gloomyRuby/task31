cmake_minimum_required(VERSION 3.8)
project(task_30)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Point.cpp Point.h Polygon.cpp Polygon.h Chord.cpp Chord.h PointsReader.cpp PointsReader.h ChordMath.cpp ChordMath.h Test/FixtureFactory.cpp Test/FixtureFactory.h Test/ChordTest.cpp Test/ChordTest.h Test/Assert.cpp Test/Assert.h ChordExtractor.cpp ChordExtractor.h Triangulation.cpp Triangulation.h TriangulationAlgorithm.cpp TriangulationAlgorithm.h NaiveTriangulationAlgorithm.cpp NaiveTriangulationAlgorithm.h Test/ChordExtractorTest.cpp Test/ChordExtractorTest.h Test/AlgorithmTests.cpp Test/AlgorithmTests.h Test/PointsReaderTest.cpp Test/PointsReaderTest.h Test/TestRunner.cpp Test/TestRunner.h FilePointReader.cpp FilePointReader.h)
add_executable(task_30 ${SOURCE_FILES})