//
//  problem_60.h
//  Prime pair sets
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include "hashMap.h"

#include <algorithm>    // std::find

using namespace std;





class problem_60 : public problem_base
{
    
    string desiredAnswer()
    {
        return "26033";
    }
    
    void subrun()
    {
        // hashMap where key is the prime and the set contains all primes which can be concatonated with it to produce a prime
        hashMap<uint64_t, set<uint64_t>> primeHash;
        // 1st million primes
        set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1);
        
        for (uint64_t prime : millionPrimes) {
            
            if (prime > 8500){
                break;
            }
            
            set<uint64_t> &curPrimeSet = *primeHash.valueForKey(prime);
            
            auto itr = primeHash.begin();
            
            while (itr != primeHash.end()) { // iterate over all current primes to see if they pass the concatonate test
                
                set<uint64_t> &curPrimeSet2 = *primeHash.valueForKey((*itr).first);
                
                //check both directions (a b) (b a)
                if (isConcatPrime((*itr).first, prime)){
                    curPrimeSet2.insert(prime);
                }
                if (isConcatPrime(prime, (*itr).first)){
                    curPrimeSet.insert((*itr).first);
                }
                
                advance(itr, 1);
                
            }
            
        }
        
        
        uint64_t minPrimeSetSum = UINT64_MAX;
        
        for (uint64_t prime1 : millionPrimes) {
            
            set<uint64_t> prime1Concats = *primeHash.valueForKey(prime1);
            
            BOOST_FOREACH(uint64_t prime2, prime1Concats) {
                
                if (prime2 > prime1 && isConcatPrime(prime1, prime2) && isConcatPrime(prime2, prime1)) {
                    
                    if (prime1 + prime2 > minPrimeSetSum) {
                        goto fin;
                    }
                    
                    set<uint64_t> prime2Concats = *primeHash.valueForKey(prime2);
                    
                    BOOST_FOREACH(uint64_t prime3, prime2Concats) {
                        
                        if (prime3 > prime2 && isConcatPrime(prime2, prime3) && isConcatPrime(prime3, prime2)) {
                            
                            if (prime1 + prime2 + prime3 > minPrimeSetSum) {
                                goto fin;
                            }
                        
                            set<uint64_t> prime3Concats = *primeHash.valueForKey(prime3);
                             
                            BOOST_FOREACH(uint64_t prime4, prime3Concats) {
                                
                                if (prime4 > prime3 && isConcatPrime(prime3, prime4) && isConcatPrime(prime4, prime3)) {
                                    
                                    if (prime1 + prime2 + prime3 + prime4 > minPrimeSetSum) {
                                        goto fin;
                                    }
                                    
                                    set<uint64_t> prime4Concats = *primeHash.valueForKey(prime4);
                                    
                                    BOOST_FOREACH(uint64_t prime5, prime4Concats) {
                                        
                                        if (prime5 > prime4 && isConcatPrime(prime4, prime5) && isConcatPrime(prime5, prime4)) {
                                            
                                            set<uint64_t> *primeSet = new set<uint64_t>();
                                            
                                            primeSet->insert(prime1);
                                            primeSet->insert(prime2);
                                            primeSet->insert(prime3);
                                            primeSet->insert(prime4);
                                            primeSet->insert(prime5);
                                            
                                            uint64_t sumOfPrimeSet = sumOfSet(primeSet);
                                            
                                            if (sumOfPrimeSet > minPrimeSetSum) {
                                                goto fin;
                                            }
                                            
                                            if (primeSet->size() == 5 && problem60Test(primeSet)) {
                                                
                                                minPrimeSetSum = sumOfPrimeSet;
                                                
                                            } else {
                                                primeSet->clear();
                                            }
                                            
                                        }
                                        
                                        
                                        
                                    }
                                }
                             }
                             
                         }
                    }
                    
                }
        
            }
            

        }
        
    fin:
        
        calculatedAnswer << minPrimeSetSum;
    }
    
    /**
     *  Check if the concatonations of all the primes in the set
     *  are also prime. Assumes that all number in the set are prime.
     *
     *  @param s set of primes
     *
     *  @return bool
     */
    bool problem60Test(set<uint64_t> *primeSet)
    {
        for (uint64_t primeA : *primeSet) {
            for (uint64_t primeB : *primeSet) {
                
                if (primeA != primeB) {
                    
                    // check both directions
                    if (!isConcatPrime(primeA, primeB)) {
                        return false;
                    }
                    if (!isConcatPrime(primeB, primeA)) {
                        return false;
                    }
                    
                }
            }
        }
        
        return true;
    }
    
    bool isConcatPrime(uint64_t primeA, uint64_t primeB)
    {
        if (primeA != primeB) {
            return primes::sharedPrimes()->isPrime(concatanate(primeA, primeB));
        }
        
        return false;
    }

};




