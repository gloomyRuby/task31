//
// Created by Oysha on 11/01/2018.
//

//
// Created by Oysha on 02/01/2018.
//


#pragma once


class Assert
{
public:
    struct Failure {};

    static void assertTrue(bool expression);
    static void assertDoubleEqual(double d1, double d2);
};
