//
// Created by Oysha on 02/01/2018.
//

#pragma once


#include <vector>
#include "Chord.h"


struct Triangulation
{
    const std::vector<Chord> chords;

    Triangulation();
    Triangulation(std::vector<Chord> &chords);
};
