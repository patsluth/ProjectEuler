//
//  problem_34.h
//  Digit factorials
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;




class problem_34 : public problem_base
{
    
    string desiredAnswer()
    {
        return "40730";
    }
    
    bool intEqualsSumOfFactorialOfDigits(uint64_t i)
    {
        uint64_t iCopy = i;
        uint64_t sum = 0;
        
        while (iCopy > 0) {
            
            sum += factorial(iCopy % 10);
            iCopy /= 10;
            
        }
        
        return (sum == i);
    }
    
    void subrun()
    {
        uint64_t sum = 0;
        
        for (uint64_t x = 3; x < 1000000; x++){ // 1! and 2! dont count
            
            if (intEqualsSumOfFactorialOfDigits(x)) {
                sum += x;
            }
            
        }
        
        calculatedAnswer << sum;
    }
    
};




