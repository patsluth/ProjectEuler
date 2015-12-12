//
//  problem_41.h
//  Pandigital prime
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_41 : public problem_base
{

    string desiredAnswer()
    {
        return "7652413";
    }
    
    void subrun()
    {
        // 1st million primes
        set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1);
        
        auto itr = millionPrimes.rbegin(); // reverse iterator. Since we are looking for the largest, the first prime to pass is the answer
        
        while (itr != millionPrimes.rend()) {
            
            if (isPandigital(*itr, numberOfDigits(*itr))) {
                calculatedAnswer << *itr;
                return;
            }
            
            advance(itr, 1);
        }
        
    }

};
