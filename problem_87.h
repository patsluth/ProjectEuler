//
//  problem_87.h
//  Prime power triples
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <set>

#include <boost/foreach.hpp>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_87 : public problem_base
{
    
    string desiredAnswer()
    {
        return "1097343";
    }
    
    void subrun()
    {
        vector<uint64_t> primeCache;
        
        for (uint64_t p = 2; p < sqrt(50000000); p++){
            if (isPrimeFast(p)){
                primeCache.push_back(p);
            }
        }
        
        set<uint64_t> count; //no duplicates
        
        BOOST_FOREACH (uint64_t x, primeCache) {
            BOOST_FOREACH (uint64_t y, primeCache) {
                BOOST_FOREACH (uint64_t z, primeCache) {
                    
                    uint64_t sum = ( (x * x) + (y * y * y) + (z * z * z * z) );
                    
                    if (sum < 50000000){
                        count.insert(sum);
                    } else {
                        break;
                    }
                    
                }
            }
        }
        
        calculatedAnswer << count.size();
    }
    
};




