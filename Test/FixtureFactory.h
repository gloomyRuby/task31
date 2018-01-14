//
// Created by Oysha on 11/01/2018.
//

//
// Created by Oysha on 03/01/2018.
//


#pragma once


#include <vector>
#include "../Point.h"
#include "../Polygon.h"


class FixtureFactory
{
public:
    Polygon createSquare() const;
    Polygon createQuad() const;
    Polygon createPentagon() const;
};
