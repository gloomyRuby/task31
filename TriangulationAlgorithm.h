//
// Created by Oysha on 02/01/2018.
//

#pragma once


#include "Triangulation.h"
#include "Polygon.h"


class TriangulationAlgorithm
{
public:
    virtual Triangulation computeTriangulation(const Polygon &p) const = 0;
};
