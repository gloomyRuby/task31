//
// Created by Oysha on 15/01/2018.
//

#include <fstream>
#include "FilePointReader.h"

std::vector<Point> *FilePointReader::pointsFromFile(std::string &filename) const
{
    std::ifstream input;
    input.open(filename);

    std::vector<Point> *points = getPoints(input);

    input.close();

    return points;
}
