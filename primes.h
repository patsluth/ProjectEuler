//
//  primes.cpp
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-12-10.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

#ifndef primes_h
#define primes_h

#include <assert.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iterator>

#include "hashMap.h"

using namespace std;





class primes
{
    
private:
    
    static primes *shared_instance;
    //the key of the first map is the n of the prime text file ex- primes2.txt key = 2
    //the key of the map of primes of that text file is the prime number
    hashMap primeData;
    
    primes()
    {
        if (shared_instance != NULL) { //already initialized
            return;
        }
    }
    
public:
    
    static primes *sharedPrimes()
    {
        if (shared_instance == NULL) {
            shared_instance = new primes;
        }
        
        return shared_instance;
    }
    
    bool isPrime(uint64_t i)
    {
        for (uint64_t n = 1; n <= 50; n++) {
            
            set<uint64_t> &nPrimeSet = loadPrimes(n); // current set for this million
            
            if (i < *nPrimeSet.rbegin()) {
                return (nPrimeSet.count(i) == 1); // set contains i, therefore is prime
            }
            
        }
        
        return false;
    }
    
    /**
     *  Load (if needed) and return set
     *
     *  @param nMillion
     *
     *  @return set<uint64_t> for primes'nMillion'.txt
     */
    set<uint64_t> &loadPrimes(uint64_t nMillion)
    {
        set<uint64_t> &set = *primeData.setForKey(nMillion);
        
        if (set.size() != 1000000) { // we havent loaded this million yet
            
            cout << "LOADING " << nMillion << endl;
            
            set.clear();
            
            stringstream file;
            file << "primes" << nMillion << ".txt";
            
            ifstream fileStream(file.str());
            
            if (fileStream) {
                
                string line;
                while (getline(fileStream, line, '\n')) { // iterate over each line
                    
                    istringstream buffer(line);
                    istream_iterator<uint64_t> number(buffer); // convert to int
                    set.insert(*number);
                    
                }
                
            } else {
                
                fprintf(stderr, "Error reading %s\n", file.str().c_str());
                
            }
            
        }
        
        return set;
        
    };
    
};

/**
 *  Allocate shared_instance pointer
 */
primes *primes::shared_instance = NULL;

#endif /* primes_h */




