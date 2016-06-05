// 
//  primes.h
//  ProjectEuler
// 
//  Created by Pat Sluth on 2015-12-10.
//  Copyright © 2015 Pat Sluth. All rights reserved.
// 

#ifndef primes_h
#define primes_h

#import <Foundation/Foundation.h>

#import <set>

#import "hashMap.h"

using namespace std;





class primes
{
    
private:
    
    static primes *shared_instance;
    
    // the key of the first map is the n of the prime text file ex- primes2.txt key = 2
    // the key of the map of primes of that text file is the prime number
    hashMap<uint64_t, set<uint64_t>> primeData;
    
public:
    
    /**
     *  Shared singleton instance
     *
     *  @return primes
     */
    static primes *sharedPrimes()
    {
        if (shared_instance == NULL) {
            shared_instance = new primes;
        }
        
        return shared_instance;
    }
    
    bool isPrime(uint64_t i);
    
    /**
     *  Get the prime after p
     *  TODO: search for the next prime if p is not prime
     *
     *  @param p prime
     *
     *  @return uint64_t
     */
    uint64_t nextPrime(uint64_t p);
    
    /**
     *  Load (if needed) and return set
     *
     *  @param nMillion
     *
     *  @return set<uint64_t> for primes'nMillion'.txt
     */
    set<uint64_t> &loadPrimes(uint64_t nMillion);
    
};

#endif /* primes_h */




