//
//  problem_67.h
//  Maximum path sum I
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_67 : public problem_base
{
    
    string desiredAnswer()
    {
        return "7273";
    }
    
    void subrun()
    {
        pyramid p = pyramidFromFile("p067_triangle.txt");
        calculatedAnswer << pyramid_SumOfMaxPath(p);
    }
    
};




