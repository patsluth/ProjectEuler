//
//  problem_16.h
//  Power digit sum
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_16 : public problem_base
{
    
    string desiredAnswer()
    {
        return "1366";
    }
    
    void subrun()
    {
        string number = "2";
        bool carryover = false;
        
        for (uint x = 1; x < 1000; x++) {
            
            int digit = (int)(number.length() - 1);
            
            while (digit >= 0) {
                
                int digitIndex = digit;
                uint digitValue = number[digitIndex] - 48; //ASCII integers start at 48
                
                uint product = digitValue * 2;
                
                if (carryover) {
                    product++;
                    carryover = false;
                }
                
                if (product >= 10) {
                    carryover = true;
                    product -= 10;
                }
                
                number[digitIndex] = product + 48; //ASCII integers start at 48
                
                if (carryover && digitIndex == 0) { //last digit
                    
                    number.insert(number.begin(), 1 + 48); //ASCII integers start at 48
                    carryover = false;
                    
                }
                
                digit--;
                
            }
            
        }
        
        //add up all digits
        uint64_t sum = 0;
        for (uint digit = 0; digit < number.length(); digit++) {
            sum += (number[digit] - 48); //ASCII integers start at 48
        }
        
        calculatedAnswer << sum;
    }
    
};




