//
//  main.cpp
//  problem_9
//  Special Pythagorean triplet
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>

using namespace std;





int main(int argc, const char * argv[])
{
    for (uint64_t x = 1; x < 1000; x++){
        for (uint64_t y = x + 1; y < 1000; y++){
            
            uint64_t z = 1000 - x - y;
            
            if ( (x * x) + (y * y) == (z * z) ){
                
                printf("The pythagorean triplet for [a + b + c = 1000] is [(%llu)^2 + (%llu)^2 = (%llu)^2]\n", x, y, z);
                printf("a * b * c = [%llu]\n\n", (x * y * z));
                return 0;
                
            }
            
        }
    }
    
    
    
    return 0;
}




