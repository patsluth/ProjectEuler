// 
//  libProjectEuler.h
//  ProjectEuler
// 
//  Created by Pat Sluth on 2015-11-20.
//  Copyright © 2015 Pat Sluth. All rights reserved.
// 

#ifndef libProjectEuler_h
#define libProjectEuler_h

#ifdef __cplusplus

#import <Foundation/Foundation.h>

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
extern bool isPalindrome(uint64_t n);
extern bool isPalindrome(string n);

extern uint64_t numberOfDigits(uint64_t n);

extern uint64_t sumOfString(string *s);
extern uint64_t sumOfDigitsInString(string *s);
extern uint64_t sumOfVector(vector<uint64_t> &v);
extern uint64_t sumOfSet(set<uint64_t> &s);

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
extern bool isPrime(uint64_t n);

/**
 *  Calcualte number of divisors
 *
 *  @param i
 *
 *  @return divisors
 */
extern uint64_t numberOfDivisors(uint64_t n);

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
extern uint64_t maxPathSum(pyramid p);

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
extern vector<uint64_t> circularVariations(uint64_t n);

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
extern properDivisors calculateProperDivisors(uint64_t n);

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
extern numberType getNumberType(uint64_t n);

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
 *  We shall say that an n-digit number, i, is pandigital if it makes use of all the digits a to b exactly once
 *  ex		i = 123456789
 *			a = 1
 *			b = 9
 *  ex		i = 145320
 *			a = 0
 *			b = 5
 *
 *  @param i
 *  @param a
 *  @param b
 *
 *  @return bool
 */
extern bool isPandigital(uint64_t n, uint64_t a, uint64_t b);

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

/**
 *  A number n is called increasing if no digit is exceeded by the digit to its left
 *  ex		n = 134468
 *
 *  @param n
 *
 *  @return bool
 */
extern bool isIncreasingNumber(uint64_t n);

/**
 *  A number n is called decreasing if no digit is exceeded by the digit to its right
 *  ex		n = 66420
 *
 *  @param n
 *
 *  @return bool
 */
extern bool isDecreasingNumber(uint64_t n);

/**
 *  A number n that is neither increasing nor decreasing is called a 'bouncy' number
 *  ex		n = 155349
 *
 *  @param n
 *
 *  @return bool
 */
extern bool isBouncyNumber(uint64_t n);

/**
 *  Reduce fraction a / b
 *
 *  @param a
 *  @param b
 */
extern void reduceFraction(uint64_t &a, uint64_t &b);
extern pair<uint64_t, uint64_t> reduceFraction2(uint64_t a, uint64_t b);

/**
 *  Greatest Common Divisor. Eulers Algorithm
 *
 *  @param a
 *  @param b
 *
 *  @return uint64_t
 */
extern uint64_t gcd(uint64_t a, uint64_t b);

/**
 *  A number n is called lychrel if it cannot form a palindrome through the iterative process of adding the reverse of it's digits (50 iterations)
 *
 *  @param n
 *
 *  @return bool
 */
extern bool isLychrel(uint64_t n);

/**
 *  Reverse a numbers digits
 *
 *  @param n
 *
 *  @return uint64_t
 */
extern uint64_t reverseNumber(uint64_t n);

/**
 *  Change the base of a number n to the specified base
 *
 *  @param n
 *  @param base
 *
 *  @return uint64_t
 */
extern uint64_t changeBase(uint64_t n, uint64_t base);

extern uint64_t ipow(uint64_t base, uint64_t exponent);

/**
 *  Calulcate vector of primes from a to b
 *
 *  @param a lower bounds
 *  @param b upper bounds
 *
 *  @return vector<uint64_t>
 */
vector<uint64_t> sieveOfEratosthenes(uint64_t a, uint64_t b);

/**
 *  Euler's totient function
 *
 *  @param n
 *
 *  @return uint64_t
 */
uint64_t totient(uint64_t n);

#endif

#endif /* libProjectEuler_h */




