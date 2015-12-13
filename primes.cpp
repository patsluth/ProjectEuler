//
//  primes.cpp
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-12-10.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

using namespace std;





/**
 *  Allocate shared_instance pointer to NULL
 */
primes *primes::shared_instance = NULL;

bool primes::isPrime(uint64_t i)
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
 *  Get the prime after p
 *  TODO: search for the next prime if p is not prime
 *
 *  @param p prime
 *
 *  @return uint64_t
 */
uint64_t primes::nextPrime(uint64_t p)
{
    for (uint64_t n = 1; n <= 50; n++) {
        
        set<uint64_t> &nPrimeSet = loadPrimes(n); // current set for this million
        
        if (p < *nPrimeSet.begin()) { // it was not found in the previous set, but is smaller than the smallest prime in this set
            return p;
        }
        
        std::set<uint64_t>::iterator itr = nPrimeSet.find(p);
        
        if (itr != nPrimeSet.end()) {
            std::advance(itr, 1);
            return *itr;
        }
        
    }
    
    return p;
}

/**
 *  Load (if needed) and return set
 *
 *  @param nMillion
 *
 *  @return set<uint64_t> for primes'nMillion'.txt
 */
set<uint64_t> &primes::loadPrimes(uint64_t nMillion)
{
    set<uint64_t> &set = *primeData.valueForKey(nMillion);
    
    if (set.size() != 1000000) { // we havent loaded this million yet
        
        cout << "LOADING " << nMillion << endl;
        
        set.clear();
        
        stringstream file;
        file << "primes" << nMillion << ".txt";
        
        ifstream fileStream = readFile(file.str());
        
        if (fileStream) {
            
            string line;
            while (getline(fileStream, line, '\n')) { // iterate over each line
                
                istringstream buffer(line);
                istream_iterator<uint64_t> number(buffer); // convert to int
                set.insert(*number);
                
            }
            
        }
        
    }
    
    return set;
}




