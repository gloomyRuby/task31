//
// Created by Oysha on 28/01/2018.
//


#pragma once


class Test
{
public:
    void RandomTest(int start, int end, int diff) const;
    void RegularTest(int start, int end, int diff) const;
    void naiveRegularTest(int start, int end, int diff) const;
    void optimizedRegularTest(int start, int end, int diff) const;
    void naivePolygonInCircleTest(int start, int end, int diff) const;
    void oprimizedPolygonInCircleTest(int start, int end, int diff) const;
};
