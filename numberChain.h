//
//  numberChain.h
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-20.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

#ifndef numberChain_h
#define numberChain_h





#include "libProjectEuler.h"

using namespace std;





//See problem 74, 92, 95 for examples
typedef vector<uint64_t> numberChain;

/**
 *  Passes the current chain and expects the next number in the number chain to be returned
 *
 *  @param numberChain
 *
 *  @return nextNumber
 */
typedef function<uint64_t (const uint64_t *)> numberChain_nextNumberFunction;

/**
 *  Passes the current chain, and the user can decide if they want to keep calculating
 *
 *  @param numberChain currentChain
 *
 *  @return numberChain_ContinueCalculatingFunction
 */
typedef function<bool (const numberChain *)> numberChain_continueCalculatingFunction;





/**
 *  Generic number chain. User specifies next number
 *  shouldContinue called with each new calculated value. Returning false will stop the calulation at that point
 *
 *  @param start
 *  @param uint64_t& shouldContinue function
 *
 *  @return numberChain
 */
inline numberChain numberChain_calculate(uint64_t start,
                                         numberChain_nextNumberFunction nextNumber,
                                         numberChain_continueCalculatingFunction continueCalculating)
{
    numberChain chain = {start};
    
    while (true){
        
        uint64_t nextEndOfChain = nextNumber(&chain.back());
        
        for (uint64_t i : chain){
            if (i == nextEndOfChain){ //duplicate
                chain.push_back(nextEndOfChain);
                return chain;
            }
        }
        
        chain.push_back(nextEndOfChain);
        
        //stop calculating
        if (continueCalculating && continueCalculating(&chain) == false){
            return chain;
        }
        
    }
}





#endif /* numberChain_h */




