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
#import <vector>

#import "hashMap.h"

using namespace std;





class primes
{
    
private:
    
    static primes *shared_instance;
	
	vector<uint64_t> primeData;
    
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
	
	static typename vector<uint64_t>::iterator begin()
	{
		return primes::sharedPrimes()->primeData.begin();
	}
	
	static typename vector<uint64_t>::iterator end()
	{
		return primes::sharedPrimes()->primeData.end();
	}
	
	static typename vector<uint64_t>::reverse_iterator rbegin()
	{
		return primes::sharedPrimes()->primeData.rbegin();
	}
	
	static typename vector<uint64_t>::reverse_iterator rend()
	{
		return primes::sharedPrimes()->primeData.rend();
	}
	
	static bool isPrime(uint64_t n);
	
	static typename vector<uint64_t>::iterator nextPrime(uint64_t n);
	
	static bool loadPrimes(uint64_t nMillion);
	
};

#endif /* primes_h */




