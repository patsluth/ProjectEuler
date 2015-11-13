//
//  main.cpp
//  problem_5
//  Smallest multiple
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

using namespace std;





uint64_t smallestMultipleOfRange(uint64_t a, uint64_t b)
{
    uint64_t m = b;
    
    if (a == 0 || b == 0 || a > b){ //invalid
        return 0;
    }
    
    while (true){
        
        bool success = true;
        
        for (uint64_t x = a; x <= b; x++){
            if (m % x != 0){
                success = false;
                break;
            }
        }
        
        if (success){
            return m;
        }
        
        m += 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    uint64_t a = 1;
    uint64_t b = 20;
    
    printf("The smallest multiple of all integers from [%llu - %llu] is [%llu]\n\n", a, b, smallestMultipleOfRange(a, b));
    
    return 0;
}




