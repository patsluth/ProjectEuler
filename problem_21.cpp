//
//  problem_21.h
//  Amicable numbers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_21 : public problem_base
{
    
    string desiredAnswer()
    {
        return "31626";
    }
    
    void subrun()
    {
        set<uint64_t> amicableNumbers; // make sure there are no duplicates
        
        for (uint64_t a = 1; a < 10000; a++){
            
            uint64_t b = sumOfVector(calculateProperDivisors(a));
            
            if (a != b && sumOfVector(calculateProperDivisors(b)) == a) {
                amicableNumbers.insert(a);
                amicableNumbers.insert(b);
            }
            
        }
        
        uint64_t sum = 0;
        
        for (auto x : amicableNumbers){
            sum += x;
        }

        calculatedAnswer << sum;
    }
    
};




