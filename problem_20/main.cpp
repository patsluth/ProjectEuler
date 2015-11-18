//
//  main.cpp
//  problem_20
//  Factorial digit sum
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>

using namespace std;





int main(int argc, const char * argv[])
{
    uint64_t fact = 1;
    
    for (uint x = 2; x <= 100; x++){
        fact *= x;
    }
    
    printf("%llu\n\n", fact);
    
    
    
    
    
    return 0;
}




