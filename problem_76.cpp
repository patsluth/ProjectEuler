//
//  problem_76.h
//  Counting summations
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_76 : public problem_base
{
    
    string desiredAnswer()
    {
        return "190569291";
    }
    
    uint64_t test(uint64_t i)
    {
        vector<uint64_t> result;
        
        while (i > 2) {
            
            result.push_back( test(i - 1) );
            result.push_back( 1 );
            
            i--;
        }
        
        
        
        return result.size();
       
        
//        if (i == 2) {
//            x = 1;
//        } else if (i == 3) {
//            x = 2;
//        }
        
        //uint64_t ii = i - 1;
        
//        uint64_t x = 2;
//        x += test(i - 1);
        
        //return x;
    }
    
    void subrun()
    {
        cout << test(100) << endl;
        
        //calculatedAnswer << test(100);
    }
    
};




