//
//  libProjectEuler.h
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-20.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

#ifndef libProjectEuler_h
#define libProjectEuler_h





#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <sstream>
#include <cxxabi.h>

using namespace std;





class problemBase
{
    
protected:
    
    stringstream calculatedAnswer;
    
    virtual string desiredAnswer(){ return ""; };
    virtual void subrun(){};
    virtual void tdd(){};
    
public:
    
    void run()
    {
        tdd();
        subrun();
        
        //class name
        cout << abi::__cxa_demangle(typeid(*this).name(), 0, 0, 0);
        cout << " ==> ";
        
        if (correct()){
            cout << "[" << calculatedAnswer.str() << "]" << endl;
        } else {
            cout << " [Calculated != Desired] [" << calculatedAnswer.str() << " != " << desiredAnswer() << "]" << endl;
        }
        
    };
    
    bool correct()
    {
        return (calculatedAnswer.str() == desiredAnswer());
    };
    
};





/**
 *  Palindrome = a number that reads the same both ways
 *  EX- 9009
 *
 *  @param x
 *
 *  @return bool
 */
bool isPalindrome(uint64_t x);

struct factor
{
    uint64_t x;
    uint64_t y;
};

/**
 *  Calculate factors of an int by finding lowest divisble number and its corresponding factor (factor tree method)
 *
 *  @param i
 *
 *  @return factor
 */
factor factorInteger(uint64_t i);

/**
 *  Quickly calculate if int is prime
 *
 *  @param i
 *
 *  @return bool
 */
bool isPrimeFast(uint64_t i);

/**
 *  Calcualte number of divisors
 *
 *  @param i
 *
 *  @return divisors
 */
uint64_t numberOfDivisors(uint64_t i);

/**
 *  Get next integer in sequence (Collatz problem)
 *
 *  if (i is even)
 *      return i / 2
 *  if (i is odd)
 *      return 3i + 1
 *
 *  @param i
 *
 *  @return integer
 */
uint64_t nextCollatzInt(uint64_t i);

typedef vector<uint64_t> pyramidRow;
typedef vector<pyramidRow> pyramid;

/**
 *  Load pyramid from txt file
 *
 *  @param file
 *
 *  @return pyramid
 */
pyramid pyramidFromFile(string file);

/**
 *  Calculate the max route (sum) through a pyramid (triangle)
 *
 *  @param p
 *
 *  @return sum
 */
uint64_t pyramid_SumOfMaxPath(pyramid p);

/**
 *  Print pyramid to console
 *
 *  @param p
 */
void printPyramid(pyramid p);

/**
 *  Calculate circular variations of a number
 *  Moves last digit to front for the number of digits in i
 *  ex- 192 -> {197, 719, 971}
 *
 *  @param i
 *
 *  @return vector
 */
vector<uint64_t> circularVariations(uint64_t i);

struct quadratic
{
    int64_t a;
    int64_t b;
    int64_t c;
};

struct quadraticRoots
{
    double x;
    double y;
};

/**
 *  Solve descriminant of a quadratic
 *
 *  @param q
 *
 *  @return descriminant
 */
double quadraticSolveSolveDescriminant(quadratic q);

/**
 *  Solv 2 roots of quadratic using the quadratic formula
 *
 *  @param q
 *
 *  @return quadraticRoots
 */
quadraticRoots quadraticSolveRoots(quadratic q);

int64_t triangleNumberForN(uint64_t n);
uint64_t nForTriangleNumber(int64_t Tn);
uint64_t pentagonalNumberForN(uint64_t n);
uint64_t nForPentagonalNumber(int64_t Pn);
uint64_t hexagonalNumberForN(uint64_t n);
uint64_t nForHexagonalNumber(int64_t Hn);





#endif /* libProjectEuler_h */




