//
//  problem_base.h
//  Root class of all problems
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#ifndef problem_base_h
#define problem_base_h





#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <cxxabi.h>

using namespace std;





class problem_base
{
    
protected:
    
    stringstream calculatedAnswer;
    
    virtual string desiredAnswer(){ return ""; };
    virtual void subrun(){};
    virtual void tdd(){};
    
public:
    
    problem_base()
    {
    }
    
    void run()
    {
        tdd();
        
        clock_t timer = clock();
        
        subrun();
        
        timer = clock() - timer;
        float timerSeconds = (float)timer/CLOCKS_PER_SEC;
        
        //class name
        cout << abi::__cxa_demangle(typeid(*this).name(), 0, 0, 0);
        
        cout.setf(ios::fixed);
        cout << " (" << showpoint << timerSeconds << " seconds) ==> ";
        
        if (correct()){
            printf("  [C] [%s]\n", calculatedAnswer.str().c_str());
        } else {
            printf("  [X] [%s != %s]\n", calculatedAnswer.str().c_str(), desiredAnswer().c_str());
        }
        
    };
    
    bool correct()
    {
        return (calculatedAnswer.str() == desiredAnswer());
    };
    
};





#endif /* problem_base_h */




