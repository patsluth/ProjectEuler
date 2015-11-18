//
//  main.cpp
//  problem_12
//  Highly divisible triangular number
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <math.h>

using namespace std;





uint64_t numberOfDivisors(uint64_t i)
{
    if (i > 1){
        
        uint64_t divisors = 0;
        
        for (uint64_t x = 1; x <= sqrt(i); x++){
            
            if (i % x == 0){
                
                divisors++;
                if (i / x != x){ //dont add perfect squares
                    divisors++;
                }
                
            }
            
        }
        
        return divisors;
        
    } else {
        
        return (i == 0) ? 0 : 1;
        
    }
}

int main(int argc, const char * argv[])
{
    uint64_t triangleNumber = 1;
    uint64_t triangleValue = 1;
    
    while (true){
        
        triangleNumber++;
        triangleValue += triangleNumber;
        
        if (numberOfDivisors(triangleValue) > 500){
            printf("[%llu] (with [%llu] divisors) is the 1st triangle number to have over 500 divisors.\n\n",
                   triangleValue,
                   numberOfDivisors(triangleValue));
            return 0;
        }
        
    }
    
    return 0;
}




