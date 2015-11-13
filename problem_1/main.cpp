//
//  main.cpp
//  problem_1
//  Multiples of 3 and 5
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>





int main(int argc, const char * argv[])
{
    int sum = 0;
    
    for (int x = 0; x < 1000; x++){
        if (x % 3 == 0 || x % 5 == 0){
            sum += x;
        }
    }
    
    printf("Sum of multiples of 3 or 5 < 1000 is [%d]\n\n", sum);
    
    return 0;
}




