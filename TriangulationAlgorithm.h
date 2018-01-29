//
// Created by Oysha on 02/01/2018.
//

#pragma once


#include "Triangulation.h"
#include "Polygon.h"


class TriangulationAlgorithm
{
public:
    virtual Triangulation computeTriangulation(Polygon &p)  = 0;
};
