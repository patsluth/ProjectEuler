//
//  main.cpp
//  problem_7
//  Largest Prime Factor
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <vector>

using namespace std;





struct factor
{
    uint64_t x;
    uint64_t y;
};

factor factorInteger(uint64_t i)
{
    for (uint64_t a = 2; a < i; a++){
        if (i % a == 0){ //divisible
            
            //return factors
            return (factor){a, i / a};
            
        }
    }
    
    return (factor){0, 0};
}

bool isPrime(factor f)
{
    return (f.x == 0 && f.y == 0);
}

int main(int argc, const char * argv[])
{
    uint64_t number = 2;
    vector<uint64_t> primeNumbers;
    
    while (primeNumbers.size() < 10001){
        
        if (isPrime(factorInteger(number))){
            primeNumbers.push_back(number);
        }
        
        number++;
        
    }
    
    printf("The 10 001st prime number is [%llu]\n\n", primeNumbers.back());
    
    return 0;
}




