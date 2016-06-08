// 
//  primes.mm
//  ProjectEuler
// 
//  Created by Pat Sluth on 2015-12-10.
//  Copyright © 2015 Pat Sluth. All rights reserved.
// 

#import "primes.h"

#import <iostream>
#import <sstream>

#import "libProjectEuler.h"





/**
 *  Allocate shared_instance pointer to NULL
 */
primes *primes::shared_instance = NULL;

bool primes::isPrime(uint64_t i)
{
	while (primes::sharedPrimes()->primeData.size() == 0 || i > *primes::sharedPrimes()->primeData.rbegin()) {
		
		uint64_t nMillion = (primes::sharedPrimes()->primeData.size() / 1000000) + 1;
		if (!primes::loadPrimes(nMillion)) {
			return false;
		}
		
	}
	
	if (binary_search(primes::sharedPrimes()->primeData.begin(), primes::sharedPrimes()->primeData.end(), i)) {
		return true;
	}
    
    return false;
}

bool primes::loadPrimes(uint64_t nMillion)
{
	if (primes::sharedPrimes()->primeData.size() != 1000000 * nMillion) { // we havent loaded this million yet
		
		printf("Loading %llu x 10^6 primes\n", nMillion);
		
		stringstream file;
		file << "Primes/primes" << nMillion << ".txt";
		
		ifstream fileStream = readFile(file.str());
		
		if (fileStream) {
			
			string line;
			while (getline(fileStream, line, '\n')) { // iterate each line
				
				istringstream buffer(line);
				istream_iterator<uint64_t> prime(buffer);
				primes::sharedPrimes()->primeData.push_back(*prime);
				
			}
			
		} else {
			
			return false;
			
		}
		
	}
	
	return true;
}




