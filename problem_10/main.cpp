//
//  main.cpp
//  problem_10
//  Summation of primes
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <math.h>

using namespace std;





bool isPrime(uint64_t i)
{
    if (i == 0 || i == 1){
        
        return false;
        
    } else if (i == 2){
        
        return true;
        
    } else {
        
        if (i % 2 == 0){ //if i is divisible by 2 and is not equal to 2, it is not prime
            return false;
        }
        
        for (uint x = 3; x <= sqrt(i); x += 2){ //only check odds
            
            if ( i % x == 0 ) {
                return false;
            }
            
        }
        
        return true;
        
    }
}

int main(int argc, const char * argv[])
{
    uint64_t primeLimit = 2000000;
    uint64_t number = 2;
    uint64_t sum = 0;
    
    while (number < primeLimit){
        
        if (isPrime(number)){
            sum += number;
        }
        
        number++;
        
    }
    
    printf("The sum of all primes < %llu = [%llu]\n\n", primeLimit, sum);
    
    return 0;
}




