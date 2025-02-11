// 
//  Problem_60.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "primes.h"
#import "hashMap.h"

#import <boost/foreach.hpp>





@interface Problem_60 : ProblemBase
{
}

@end





@implementation Problem_60

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	completion([self solveProblem], self.endTime);	// 26033
}

- (id)solveProblem
{
	// hashMap where key is the prime and the set contains all primes which can be concatonated with it to produce a prime
	hashMap<uint64_t, set<uint64_t>> primeHash;
	primes::loadPrimes(1);
	
	for (auto prime = primes::begin(); prime != primes::end(); advance(prime, 1)) {
		
		if (*prime > 8500) {
			break;
		}
		
		set<uint64_t> &curPrimeSet = *primeHash.valueForKey(*prime);
		
		// iterate over all current primes to see if they pass the concatonate test
		for (auto itr = primeHash.begin(); itr != primeHash.end(); advance(itr, 1)) {
			
			set<uint64_t> &curPrimeSet2 = *primeHash.valueForKey((*itr).first);
			
			// check both directions (a b) (b a)
			if (isConcatPrime((*itr).first, *prime)) {
				curPrimeSet2.insert(*prime);
			}
			if (isConcatPrime(*prime, (*itr).first)) {
				curPrimeSet.insert((*itr).first);
			}
			
		}
		
	}
	
	
	uint64_t minPrimeSetSum = UINT64_MAX;
	
	for (auto prime1 = primes::begin(); prime1 != primes::end(); advance(prime1, 1)) {
		
		set<uint64_t> prime1Concats = *primeHash.valueForKey(*prime1);
		
		BOOST_FOREACH(uint64_t prime2, prime1Concats) {
			
			if (prime2 > *prime1 && isConcatPrime(*prime1, prime2) && isConcatPrime(prime2, *prime1)) {
				
				if (*prime1 + prime2 > minPrimeSetSum) {
					goto fin;
				}
				
				set<uint64_t> prime2Concats = *primeHash.valueForKey(prime2);
				
				BOOST_FOREACH(uint64_t prime3, prime2Concats) {
					
					if (prime3 > prime2 && isConcatPrime(prime2, prime3) && isConcatPrime(prime3, prime2)) {
						
						if (*prime1 + prime2 + prime3 > minPrimeSetSum) {
							goto fin;
						}
						
						set<uint64_t> prime3Concats = *primeHash.valueForKey(prime3);
						
						BOOST_FOREACH(uint64_t prime4, prime3Concats) {
							
							if (prime4 > prime3 && isConcatPrime(prime3, prime4) && isConcatPrime(prime4, prime3)) {
								
								if (*prime1 + prime2 + prime3 + prime4 > minPrimeSetSum) {
									goto fin;
								}
								
								set<uint64_t> prime4Concats = *primeHash.valueForKey(prime4);
								
								BOOST_FOREACH(uint64_t prime5, prime4Concats) {
									
									if (prime5 > prime4 && isConcatPrime(prime4, prime5) && isConcatPrime(prime5, prime4)) {
										
										set<uint64_t> *primeSet = new set<uint64_t>();
										
										primeSet->insert(*prime1);
										primeSet->insert(prime2);
										primeSet->insert(prime3);
										primeSet->insert(prime4);
										primeSet->insert(prime5);
										
										uint64_t sumOfPrimeSet = sumOfSet(*primeSet);
										
										if (sumOfPrimeSet > minPrimeSetSum) {
											goto fin;
										}
										
										if (primeSet->size() == 5 && p60Condition(primeSet)) {
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
	
	return @(minPrimeSetSum);
}

/**
 *  Check if the concatonations of all the primes in the set
 *  are also prime. Assumes that all number in the set are prime.
 *
 *  @param s set of primes
 *
 *  @return bool
 */
bool p60Condition(set<uint64_t> *primeSet)
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
		return primes::isPrime(concatanate(primeA, primeB));
	}
	
	return false;
}

@end





