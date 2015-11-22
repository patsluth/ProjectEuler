//
//  main.cpp
//  problem_3
//  Largest Prime Factor
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "libProjectEuler.h"





using namespace std;





class problem_3 : public problemBase
{
    
    string desiredAnswer()
    {
        return "6857";
    }
    
    void subrun()
    {
        uint64_t number = 600851475143;
        
        vector<uint64_t> primeFactors;
        
        while (true){
            
            factor f = factorInteger(number);
            number = f.y;
            
            if (f.x != 0 && f.y != 0){ //we can keep on factoring
                
                //pop the last added prime factor because it is still factorable
                if (!primeFactors.empty()){
                    primeFactors.pop_back();
                }
                
                //push both factors
                //x is guaranteed to be the smallest it can
                //y will be removed and factored again in the next iteration
                primeFactors.push_back(f.x);
                primeFactors.push_back(f.y);
                
            } else {
                break; //exit loop
            }
            
        }
        
        if (!primeFactors.empty()){
            calculatedAnswer << primeFactors.back();
        }
    }
    
};

