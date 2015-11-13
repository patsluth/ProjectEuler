//
//  main.cpp
//  problem_4
//  Largest palindrome product
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

using namespace std;





bool isPalindrome(int x)
{
    int numDigits = 0;
    int *digits = new int[numDigits];
    
    while (x > 0){
        
        //copy current digit array
        int *oldDigits = new int[numDigits];
        copy(digits, digits + numDigits, oldDigits);
        
        //increase current digit arrray size and copy previous values back
        digits = new int[numDigits + 1];
        copy(oldDigits, oldDigits + numDigits, digits);
        
        //set new value to current digit
        digits[numDigits] = x % 10;
        
        //remove current digit from x
        x /= 10;
        numDigits++;
        
    }
    
    for (int y = 0; y < numDigits / 2; y++){
        
        if (digits[y] != digits[numDigits - 1 - y]){ //compare corresponding elements
            return false;
        }
        
    }
    
    return true;
}

int main(int argc, const char * argv[])
{
    int factorOne = 0;
    int factorTwo = 0;
    int largestProduct = 0;
    
    for (int x = 100; x <= 999; x++){ //all 3 digit integers
        for (int y = 100; y <= 999; y++){ //all 3 digit integers
            
            int currentProduct = x * y;
            
            if (isPalindrome(currentProduct) && currentProduct > largestProduct){
                factorOne = x;
                factorTwo = y;
                largestProduct = currentProduct;
            }
            
        }
    }
    
    printf("Largest product is [%d x %d = %d]\n\n", factorOne, factorTwo, largestProduct);
    
    return 0;
}




