//
//  libProjectEuler.h
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-20.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

#ifndef libProjectEuler_h
#define libProjectEuler_h

#import <Foundation/Foundation.h>

#ifdef __cplusplus

#include <iostream>
#import <sstream>
#import <fstream>       // for ifstream

#import <string>
#import <vector>
#import <set>
#import <list>
#import <forward_list>

#import <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef vector<uint64_t> pyramidRow;
typedef vector<pyramidRow> pyramid;





/**
 *  Return a filestream with file. null if failed
 *
 *  @param file name
 *
 *  @return ifstream
 */
extern ifstream readFile(string file);

/**
 *  Palindrome = a number that reads the same both ways
 *  EX- 9009
 *
 *  @param x
 *
 *  @return bool
 */
extern bool isPalindrome(uint64_t x);
extern bool isPalindrome(string i);

/**
 *  Get a list of individual digits of a number
 *
 *  @param i
 *
 *  @return list
 */
extern forward_list<uint64_t> getDigits(uint64_t i);
extern uint64_t numberOfDigits(uint64_t i);

extern uint64_t sumOfVector(vector<uint64_t> *v);
extern uint64_t sumOfSet(set<uint64_t> *s);
extern uint64_t sumOfList(list<uint64_t> *l);
extern uint64_t sumOfList(forward_list<uint64_t> *l);

inline uint64_t factorial(uint64_t x)
{
	if (x == 0 || x == 1) {
		return 1;
	} else {
		return x * factorial(x - 1);
	}
}

inline cpp_int factorial_cpp_int(cpp_int x)
{
	if (x == 0 || x == 1) {
		return 1;
	} else {
		return x * factorial_cpp_int(x - 1);
	}
}

struct Factor
{
	uint64_t x;
	uint64_t y;
};
typedef struct Factor Factor;

/**
 *  Calculate factors of an int by finding lowest divisble number and its corresponding factor (factor tree method)
 *
 *  @param i
 *
 *  @return factor
 */
extern Factor factorInteger(uint64_t i);

extern bool isFactorPrime(Factor f);


/**
 *  Calculate if int is prime
 *
 *  @param i
 *
 *  @return bool
 */
extern bool isPrime(uint64_t i);

/**
 *  Calcualte number of divisors
 *
 *  @param i
 *
 *  @return divisors
 */
extern uint64_t numberOfDivisors(uint64_t i);

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
extern uint64_t nextCollatzInt(uint64_t i);

/**
 *  n Choose r
 *
 *  @param n
 *  @param r
 *
 *  @return cpp_int
 */
extern cpp_int nCr(cpp_int n, cpp_int r);

/**
 *  Load pyramid from txt file
 *
 *  @param file
 *
 *  @return pyramid
 */
extern pyramid pyramidFromFile(string file);

/**
 *  Calculate the max route (sum) through a pyramid (triangle)
 *
 *  @param p
 *
 *  @return sum
 */
extern uint64_t pyramid_SumOfMaxPath(pyramid p);

/**
 *  Print pyramid to console
 *
 *  @param p
 */
extern void printPyramid(pyramid p);

/**
 *  Calculate circular variations of a number
 *  Moves last digit to front for the number of digits in i
 *  ex- 192 -> {197, 719, 971}
 *
 *  @param i
 *
 *  @return vector
 */
extern vector<uint64_t> circularVariations(uint64_t i);

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
extern double quadraticSolveSolveDescriminant(quadratic q);

/**
 *  Solv 2 roots of quadratic using the quadratic formula
 *
 *  @param q
 *
 *  @return quadraticRoots
 */
extern quadraticRoots quadraticSolveRoots(quadratic q);

// 3
extern int64_t triangleForN(int64_t n);
extern int64_t nForTriangle(int64_t Tn);
// 5
extern int64_t pentagonalForN(int64_t n);
extern int64_t nForPentagonal(int64_t Pn);
// 6
extern int64_t hexagonalForN(int64_t n);
extern int64_t nForHexagonal(int64_t Hn);
// 7
extern int64_t heptagonalForN(int64_t n);
extern int64_t nForHeptagonal(int64_t Hn);
// 8
extern int64_t octagonalForN(int64_t n);
extern int64_t nForOctagonal(int64_t On);

typedef vector<uint64_t> properDivisors;
/**
 *  Calculate the proper divisors of a number (all divisors exluding the number itself)
 *
 *  @param i
 *
 *  @return vector containing proper divisors
 */
extern properDivisors *calculateProperDivisors(uint64_t i);

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
extern numberType getNumberType(uint64_t i);

/**
 *  Concatonate 2 integers
 *  ex 78 and 96 produce 7896
 *  ex 96 and 78 produce 9678
 *
 *  @param a
 *  @param b
 *
 *  @return uint64_t
 */
extern uint64_t concatanate(uint64_t a, uint64_t b);

/**
 *  A number is pandigital if it contains the digits 1 through n exactly
 *  ex- n = 9 123456789
 *  ex- n = 4 4321
 *  ex- n = 6 132465
 *
 *  @param i
 *
 *  @return bool
 */
extern bool isPandigital(uint64_t i, uint64_t n);

/**
 *  A number a is a permutation of another number b
 *	if it contains the exact same digits in any order
 *
 *  @param a
 *  @param b
 *
 *  @return bool
 */
extern bool isPermutation(uint64_t a, uint64_t b);

/**
 *  Get the nth fibonacci number
 *
 *  @param n
 *
 *  @return uint64_t
 */
extern uint64_t fibonacci(uint64_t n);

/**
 *  Get the english word for a given number n
 *
 *  @param n
 *
 *  @return string
 */
extern string englishRepresentationOfNumber(uint64_t n);

#endif

#endif /* libProjectEuler_h */




