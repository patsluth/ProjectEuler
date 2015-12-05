//
//  libProjectEuler.h
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-20.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

#ifndef libProjectEuler_h
#define libProjectEuler_h





#include <vector>

using namespace std;





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

inline int64_t factorial(int64_t x)
{
    if (x == 0 || x == 1) {
        return 1;
    } else {
        return x * factorial(x - 1);
    }
}

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




//3
int64_t triangleForN(uint64_t n);
uint64_t nForTriangle(int64_t Tn);
//5
uint64_t pentagonalForN(uint64_t n);
uint64_t nForPentagonal(int64_t Pn);
//6
uint64_t hexagonalForN(uint64_t n);
uint64_t nForHexagonal(int64_t Hn);
//7
uint64_t heptagonalForN(uint64_t n);
uint64_t nForHeptagonal(int64_t Hn);
//8
uint64_t octagonalForN(uint64_t n);
uint64_t nForOctagonal(int64_t On);




typedef vector<uint64_t> properDivisors;
/**
 *  Calculate the proper divisors of a number (all divisors exluding the number itself)
 *
 *  @param i
 *
 *  @return vector containing proper divisors
 */
properDivisors calculateProperDivisors(uint64_t i);
uint64_t sumOfProperDivisors(properDivisors properDivisors);

enum numberType
{
    NumberType_Deficient, // sum of proper divisors < n
    NumberType_Perfect, // sum of proper divisors = n
    NumberType_Abundant // sum of proper divisors > n
};

/**
 *  Get the number type (Deficient, Perfect, Abundant)
 *
 *  @param i
 *
 *  @return bool
 */
numberType getNumberType(uint64_t i);



#endif /* libProjectEuler_h */




