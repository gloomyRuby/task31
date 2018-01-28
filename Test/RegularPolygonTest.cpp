//
// Created by Oysha on 28/01/2018.
//

#include "RegularPolygonTest.h"
#include "../TestClass/RegularPolygon.h"
#include "Assert.h"


void RegularPolygonTest::test() const
{
    RegularPolygon sut;

    // given

    // when
    Polygon p = sut.createRegularPolygon(4, 1);

    // then
    Assert::assertTrue(p.vertexCount() == 4);
    Assert::assertTrue(p.vertexAtIndex(0) == Point(1,  1));
    Assert::assertTrue(p.vertexAtIndex(1) == Point(-1,  1));
    Assert::assertTrue(p.vertexAtIndex(2) == Point(-1, -1));
    Assert::assertTrue(p.vertexAtIndex(3) == Point(1, -1));
}
