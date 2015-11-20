//
//  main.cpp
//  problem_4
//  Largest palindrome product
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include "libProjectEuler.h"

using namespace std;





class problem_4 : public problemBase
{
    
    string desiredAnswer()
    {
        return "906609";
    }
    
    void subrun()
    {
        uint64_t factorOne = 0;
        uint64_t factorTwo = 0;
        uint64_t largestProduct = 0;
        
        for (uint64_t x = 100; x <= 999; x++){ //all 3 digit integers
            for (uint64_t y = 100; y <= 999; y++){ //all 3 digit integers
                
                uint64_t currentProduct = x * y;
                
                if (isPalindrome(currentProduct) && currentProduct > largestProduct){
                    factorOne = x;
                    factorTwo = y;
                    largestProduct = currentProduct;
                }
                
            }
        }
        
        calculatedAnswer << largestProduct;
    }
    
};




