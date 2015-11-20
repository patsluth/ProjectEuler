//
// main.cpp
// problem_45
// Circular primes
//
// Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <vector>

#include "libProjectEuler.h"

using namespace std;




class problem_35 : public problemBase
{
    
    string desiredAnswer()
    {
        return "55";
    }
    
    void subrun()
    {
        uint64_t primeCount = 0;
        
        for (uint64_t x = 1; x < 1000000; x++){
            
            vector<uint64_t> circularValueVariations = circularVariations(x);
            bool allCircularVariationsPrime = true;
            
            for (uint64_t cur : circularValueVariations){
                if (allCircularVariationsPrime == true){
                    allCircularVariationsPrime = isPrimeFast(cur);
                }
            }
            
            if (allCircularVariationsPrime){
                primeCount++;
            }
            
        }
        
        calculatedAnswer << primeCount;
    }
    
};




