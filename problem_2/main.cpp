//
//  main.cpp
//  problem_2
//  Even Fibonacci Numbers
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>





int main(int argc, const char * argv[])
{
    int sum = 0;
    
    int previousFib = 1;
    int currentFib = 1;
    
    while (currentFib <= 4000000) {
        
        //process current fib
        if (currentFib % 2 == 0){ //even
            sum += currentFib;
        }
        
        int temp = previousFib;
        previousFib = currentFib;
        currentFib = currentFib + temp;
        
    }
    
    printf("Sum of even fibonacci numbers <= 4 million is [%d]\n\n", sum);
    
    return 0;
}




