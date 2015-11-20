//
//  libProjectEuler.cpp
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-20.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

#include "libProjectEuler.h"

#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iterator>

#include <math.h>

using namespace std;





bool isPalindrome(uint64_t i)
{
    int numDigits = 0;
    int *digits = new int[numDigits];
    
    while (i != 0){
        
        //copy current digit array
        int *oldDigits = new int[numDigits];
        copy(digits, digits + numDigits, oldDigits);
        
        //increase current digit arrray size and copy previous values back
        digits = new int[numDigits + 1];
        copy(oldDigits, oldDigits + numDigits, digits);
        
        //set new value to current digit
        digits[numDigits] = i % 10;
        
        //remove current digit from x
        i /= 10;
        numDigits++;
        
    }
    
    for (int y = 0; y < numDigits / 2; y++){
        
        if (digits[y] != digits[numDigits - 1 - y]){ //compare corresponding elements
            return false;
        }
        
    }
    
    return true;
}

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

bool isPrimeFast(uint64_t i)
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

uint64_t nextCollatzInt(uint64_t i)
{
    if (i % 2 == 0){
        return i / 2;
    } else {
        return (3 * i) + 1;
    }
}

pyramid pyramidFromFile(string file)
{
    ifstream triangleSrc(file);
    pyramid p;
    
    if (triangleSrc){
        
        string line;
        while (getline(triangleSrc, line, '\n')) { //split txt file by line
            
            pyramidRow pRow;
            
            istringstream buf(line);
            istream_iterator<uint> beg(buf), end;
            vector<uint> numbers(beg, end);
            
            for(uint number: numbers){ //individual numbers
                pRow.push_back(number);
            }
            
            p.push_back(pRow);
            
        }
        
    } else {
        
        fprintf(stderr, "Error reading %s\n", file.c_str());
        
    }
    
    return p;
}

uint64_t pyramid_SumOfMaxPath(pyramid p)
{
    while (p.size() > 1){
        
        //pop both bottom rows
        pyramidRow pRow = p.back();
        p.pop_back();
        pyramidRow pParentRow = p.back();
        p.pop_back();
        
        //calculate new bottom row and push back to stack
        //sets each parentRow value to the larger sum of itself and its children
        for (uint x = 0; x < (uint)pParentRow.size(); x++){
            
            uint64_t leftChild = pRow[x];
            uint64_t rightChild = pRow[x + 1];
            
            pParentRow[x] += max(leftChild, rightChild); //add parent and larger value of its children
            
        }
        
        p.push_back(pParentRow);
        
    }
    
    return p.back().front();
}

void printPyramid(pyramid p)
{
    for (pyramidRow pRow : p){
        for (uint64_t num : pRow){
            printf("%llu ", num);
        }
        
        printf("\n");
        
    }
}

vector<uint64_t> circularVariations(uint64_t i)
{
    vector<uint64_t> iDigits;
    
    uint64_t iCopy = i;
    
    while (iCopy != 0) {
        
        iDigits.insert(iDigits.begin(), iCopy % 10);
        iCopy /= 10;
        
    }
    
    vector<uint64_t> circularVariations;
    
    for (uint x = 0; x < iDigits.size(); x++){ //move last digit to front
        
        uint64_t lastDigit = iDigits.back();
        iDigits.pop_back();
        iDigits.insert(iDigits.begin(), lastDigit);
        
        uint64_t digitToInt = 0; //convert the vector of digits back into an integer
        for (uint y = 0; y < iDigits.size(); y++){
            digitToInt += iDigits[iDigits.size() - y - 1] * pow(10, y);
        }
        
        circularVariations.push_back(digitToInt);
        
    }
    
    return circularVariations;
}




