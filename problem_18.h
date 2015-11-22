//
// main.cpp
// problem_18
// Maximum path sum I
//
// Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>

#include "libProjectEuler.h"

using namespace std;





class problem_18 : public problemBase
{
    
    string desiredAnswer()
    {
        return "1074";
    }
    
    void subrun()
    {
        pyramid p = pyramidFromFile("p018_triangle.txt");
        calculatedAnswer << pyramid_SumOfMaxPath(p);
    }
    
};




