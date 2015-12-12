//
//  problem_36.h
//  Double-base palindromes
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_36 : public problem_base
{
    
    string desiredAnswer()
    {
        return "872187";
    }
    
    void subrun()
    {
        uint64_t sum = 0;
        
        for (uint64_t i = 0; i < 1000000; i++) {
            
            if (isPalindrome(i)) {
                
                string binaryI = bitset<64>(i).to_string();
                binaryI = binaryI.erase(0, binaryI.find_first_not_of("0")); // erase all extra 0's
                
                if (isPalindrome(binaryI)) {
                    sum += i;
                }
                
            }
            
        }
        
        calculatedAnswer << sum;
    }
    
};

