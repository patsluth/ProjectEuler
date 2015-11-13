//
//  main.cpp
//  problem_6
//  Sum square difference
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

using namespace std;





int main(int argc, const char * argv[])
{
    uint64_t sumOfSquares = 0;
    uint64_t sum = 0;
    
    for (uint x = 1; x <= 100; x++){
        sumOfSquares += (x * x);
        sum += x;
    }
    
    uint64_t sumSquared = (sum * sum);
    
    printf("Sum of squares (1-100): [%llu]\n", sumSquared);
    printf("Sum of (1-100) squared: [%llu]\n", sumOfSquares);
    printf("Difference: [%llu]\n\n", sumSquared - sumOfSquares);
    
    return 0;
}




