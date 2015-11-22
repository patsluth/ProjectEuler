//
// main.cpp
// problem_45
// Triangular, pentagonal, and hexagonal
//
// Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <assert.h>

#include "libProjectEuler.h"

using namespace std;





class problem_45 : public problemBase
{
    
    string desiredAnswer()
    {
        return "1533776805";
    }
    
    void subrun()
    {
        uint64_t n = 286;
        
        //number is triangle, pentagonal, and hexagonal
        while (nForPentagonalNumber(triangleNumberForN(n)) == 0 || nForHexagonalNumber(triangleNumberForN(n)) == 0) {
            n++;
        }
        
        calculatedAnswer << triangleNumberForN(n);
        
    }
    
    void tdd()
    {
        assert(triangleNumberForN(1) == 1);
        assert(triangleNumberForN(2) == 3);
        assert(triangleNumberForN(3) == 6);
        assert(triangleNumberForN(4) == 10);
        assert(triangleNumberForN(5) == 15);
        //
        assert(nForTriangleNumber(1) == 1);
        assert(nForTriangleNumber(3) == 2);
        assert(nForTriangleNumber(6) == 3);
        assert(nForTriangleNumber(10) == 4);
        assert(nForTriangleNumber(15) == 5);
        
        
        assert(pentagonalNumberForN(1) == 1);
        assert(pentagonalNumberForN(2) == 5);
        assert(pentagonalNumberForN(3) == 12);
        assert(pentagonalNumberForN(4) == 22);
        assert(pentagonalNumberForN(5) == 35);
        //
        assert(nForPentagonalNumber(1) == 1);
        assert(nForPentagonalNumber(5) == 2);
        assert(nForPentagonalNumber(12) == 3);
        assert(nForPentagonalNumber(22) == 4);
        assert(nForPentagonalNumber(35) == 5);
        
        
        assert(hexagonalNumberForN(1) == 1);
        assert(hexagonalNumberForN(2) == 6);
        assert(hexagonalNumberForN(3) == 15);
        assert(hexagonalNumberForN(4) == 28);
        assert(hexagonalNumberForN(5) == 45);
        //
        assert(nForHexagonalNumber(1) == 1);
        assert(nForHexagonalNumber(6) == 2);
        assert(nForHexagonalNumber(15) == 3);
        assert(nForHexagonalNumber(28) == 4);
        assert(nForHexagonalNumber(45) == 5);
    }
    
};




