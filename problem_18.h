//
//  problem_18.h
//  Maximum path sum I
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
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




