//
//  main.cpp
//  problem_3
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

int main(int argc, const char * argv[])
{
    uint64_t number = 600851475143;
    uint64_t numberCopy = number;
    
    vector<uint64_t> primeFactors;
    
    while (true){
        
        factor f = factorInteger(number);
        number = f.y;
        
        if (f.x != 0 && f.y != 0){ //we can keep on factoring
            
            //pop the last added prime factor because it is still factorable
            if (!primeFactors.empty()){
                primeFactors.pop_back();
            }
            
            //push both factors
            //x is guaranteed to be the smallest it can
            //y will be removed and factored again in the next iteration
            primeFactors.push_back(f.x);
            primeFactors.push_back(f.y);
            
        } else {
            break; //exit loop
        }
        
    }
    
    if (primeFactors.empty()){
        
        printf("No prime factors of [%llu]\n", numberCopy);
        
    } else {
        
        printf("The prime factors of [%llu] are [ ", numberCopy);
        
        for (vector<uint64_t>::iterator itr = primeFactors.begin(); itr != primeFactors.end(); ++itr){
            cout << *itr << ' ';
        }
        
        printf("]\nThe largest prime factor of [%llu] is [%llu]\n\n", numberCopy, primeFactors.back());
        
    }
    
    return 0;
}




