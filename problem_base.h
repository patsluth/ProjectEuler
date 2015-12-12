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





#include <sstream>
#include <cxxabi.h>

using namespace std;





class problem_base
{
    
protected:
    
    stringstream calculatedAnswer;
    
    virtual string desiredAnswer() { return ""; };
    virtual void subrun() {};
    virtual void tdd() {};
    
public:
    
    void run()
    {
#ifdef DEBUG
        tdd();
#endif
        
        clock_t timer = clock();
        
        subrun();
        
        timer = clock() - timer;
        float timerSeconds = (float)timer/CLOCKS_PER_SEC;
        
        //class name
        cout << abi::__cxa_demangle(typeid(*this).name(), 0, 0, 0);
        
        cout.setf(ios::fixed);
        cout << "\t\t" << showpoint << timerSeconds;
        
        cout << "\t\t(" << calculatedAnswer.str();
        cout << (correct() ? " == " : " != ");
        cout << desiredAnswer() << ")";
        
        cout << endl;
        
    };
    
    bool correct()
    {
        return (calculatedAnswer.str() == desiredAnswer());
    };
    
};





#endif /* problem_base_h */




