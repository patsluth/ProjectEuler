//
//  problem_38.h
//  Pandigital multiples
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_38 : public problem_base
{

    string desiredAnswer()
    {
        return "932718654";
    }
    
    void subrun()
    {
        uint64_t largestPandigital = 0;
        
        for (uint64_t x = 1; x < 10000; x++) {
            
            uint64_t y = x;
            
            for (uint64_t n = 2; n < 10; n++) { // 2 - 9. We already have 1 by setting y to x
                
                y = concatanate(y, x * n);
                
                if (y > 987654321) { // largest possible 9 digit pandigital number
                    break;
                }
                
                if (isPandigital(y, 9)){
                    if (largestPandigital < y) {
                        largestPandigital = y;
                    } else {
                        break;
                    }
                }
                
            }
            
        }
        
        calculatedAnswer << largestPandigital;
    }

};
