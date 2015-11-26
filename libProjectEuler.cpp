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
    ifstream fileStream(file);
    pyramid p;
    
    if (fileStream){
        
        string line;
        while (getline(fileStream, line, '\n')) { //split txt file by line
            
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

double quadraticSolveSolveDescriminant(quadratic q)
{
    return (q.b * q.b) - (4.0 * q.a * q.c);
}

quadraticRoots quadraticSolveRoots(quadratic q)
{
    int64_t descriminant = quadraticSolveSolveDescriminant(q);
    
    if (descriminant < 0){
        return {0, 0};
    }
    
    double numeratorAdd = -q.b + sqrt(descriminant);
    double numeratorSubtract = -q.b - sqrt(descriminant);
    double denomenator = 2.0 * q.a;
    
    return {numeratorAdd / denomenator, numeratorSubtract / denomenator};
}

int64_t triangleNumberForN(uint64_t n)
{
    uint64_t Tn = n * (n + 1);
    Tn /= 2;
    return Tn;
}

uint64_t nForTriangleNumber(int64_t Tn)
{
    quadratic q = {1, 1, (-2 * Tn)};
    quadraticRoots roots = quadraticSolveRoots(q);
    
    double largerRoot = max(roots.x, roots.y);
    
    if (largerRoot - (int64_t)largerRoot == 0){ //whole number
        return largerRoot;
    }
    
    return 0;
}

uint64_t pentagonalNumberForN(uint64_t n)
{
    uint64_t Pn = n * ( (3 * n) - 1 );
    Pn /= 2;
    return Pn;
}

uint64_t nForPentagonalNumber(int64_t Pn)
{
    quadratic q = {3, -1, (-2 * Pn)};
    quadraticRoots roots = quadraticSolveRoots(q);
    
    double largerRoot = max(roots.x, roots.y);
    
    if (largerRoot - (int64_t)largerRoot == 0){ //whole number
        return largerRoot;
    }
    
    return 0;
}

uint64_t hexagonalNumberForN(uint64_t n)
{
    uint64_t Hn = n * ( (2 * n) - 1 );
    return Hn;
}

uint64_t nForHexagonalNumber(int64_t Hn)
{
    quadratic q = {2, -1, (-1 * Hn)};
    quadraticRoots roots = quadraticSolveRoots(q);
    
    double largerRoot = max(roots.x, roots.y);
    
    if (largerRoot - (int64_t)largerRoot == 0){ //whole number
        return largerRoot;
    }
    
    return 0;
}





/**
 *  Calculate the proper divisors of a number (all divisors exluding the number itself)
 *
 *  @param i
 *
 *  @return vector containing proper divisors
 */
properDivisors calculateProperDivisors(uint64_t i)
{
    vector<uint64_t> properDivisors = {1};
    
    for (uint64_t x = 2; x <= sqrt(i); x++){
        if ( (i / x) * x == i ){
            properDivisors.push_back(x);
            if ( (i / x) != x){ //dont add same multiple twice
                properDivisors.push_back(i / x);
            }
        }
    }
    
    return properDivisors;
}

uint64_t sumOfProperDivisors(properDivisors properDivisors)
{
    uint64_t sum = 0;
    
    for (uint64_t i : properDivisors){
        sum += i;
    }
    
    return sum;
}




