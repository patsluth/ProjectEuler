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

using namespace std;

#define XCODE_COLORS_ESCAPE "\033["

#define XCODE_COLORS_RESET_FG  XCODE_COLORS_ESCAPE "fg;" // Clear any foreground color
#define XCODE_COLORS_RESET_BG  XCODE_COLORS_ESCAPE "bg;" // Clear any background color
#define XCODE_COLORS_RESET     XCODE_COLORS_ESCAPE ";"   // Clear any foreground or background color





class problemBase
{
    
protected:
    
    stringstream calculatedAnswer;
    
    virtual void subrun(){};
    virtual string desiredAnswer(){ return ""; };
    
public:
    
    void run()
    {
        subrun();
        
        if (correct()){
            cout << "Correct: ";
        } else {
            cout << XCODE_COLORS_ESCAPE << "fg220,0,0;" << "Incorrect: " << XCODE_COLORS_RESET;
        }
        
        cout << XCODE_COLORS_ESCAPE << "fg255,255,255;" << calculatedAnswer.str() << "   [" << desiredAnswer() << "]" << XCODE_COLORS_RESET << endl;
        
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





#endif /* libProjectEuler_h */




