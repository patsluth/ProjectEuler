//
//  problem_45.h
//  Triangular, pentagonal, and hexagonal
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_45 : public problem_base
{
    
    string desiredAnswer()
    {
        return "1533776805";
    }
    
    void subrun()
    {
        uint64_t n = 286;
        
        //number is triangle, pentagonal, and hexagonal
        while (nForPentagonal(triangleForN(n)) == 0 || nForHexagonal(triangleForN(n)) == 0) {
            n++;
        }
        
        calculatedAnswer << triangleForN(n);
        
    }
    
    void tdd()
    {
        assert(triangleForN(1) == 1);
        assert(triangleForN(2) == 3);
        assert(triangleForN(3) == 6);
        assert(triangleForN(4) == 10);
        assert(triangleForN(5) == 15);
        //
        assert(nForTriangle(1) == 1);
        assert(nForTriangle(3) == 2);
        assert(nForTriangle(6) == 3);
        assert(nForTriangle(10) == 4);
        assert(nForTriangle(15) == 5);
        
        
        assert(pentagonalForN(1) == 1);
        assert(pentagonalForN(2) == 5);
        assert(pentagonalForN(3) == 12);
        assert(pentagonalForN(4) == 22);
        assert(pentagonalForN(5) == 35);
        //
        assert(nForPentagonal(1) == 1);
        assert(nForPentagonal(5) == 2);
        assert(nForPentagonal(12) == 3);
        assert(nForPentagonal(22) == 4);
        assert(nForPentagonal(35) == 5);
        
        
        assert(hexagonalForN(1) == 1);
        assert(hexagonalForN(2) == 6);
        assert(hexagonalForN(3) == 15);
        assert(hexagonalForN(4) == 28);
        assert(hexagonalForN(5) == 45);
        //
        assert(nForHexagonal(1) == 1);
        assert(nForHexagonal(6) == 2);
        assert(nForHexagonal(15) == 3);
        assert(nForHexagonal(28) == 4);
        assert(nForHexagonal(45) == 5);
    }
    
};




