// 
//  libProjectEuler.mm
//  ProjectEuler
// 
//  Created by Pat Sluth on 2015-11-20.
//  Copyright © 2015 Pat Sluth. All rights reserved.
// 

#import "libProjectEuler.h"

#import <algorithm>    // std::copy





extern ifstream readFile(string file)
{
	ifstream fileStream(file);
	
	if (!fileStream) {
		fprintf(stderr, "Error reading %s\n", file.c_str());
	}
	
	return fileStream;
}

extern bool isPalindrome(uint64_t n)
{
	return isPalindrome(to_string(n));
}

extern bool isPalindrome(string n)
{
    for (uint64_t x = 0; x < n.size() / 2; x += 1) {

        if (n[x] != n[n.size() - 1 - x]) { // compare corresponding elements
            return false;
        }

    }

    return true;
}

extern uint64_t numberOfDigits(uint64_t n)
{
	return ceil(log10(n + 1.0));
}

extern uint64_t sumOfString(string *s)
{
	uint64_t sum = 0;
	
	for (uint64_t i = 0; i < (*s).length(); i += 1) {
		sum += (uint64_t)(*s)[i];
	}
	
	return sum;
}

extern uint64_t sumOfDigitsInString(string *s)
{
	uint64_t sum = 0;
	
	for (uint64_t i = 0; i < (*s).length(); i += 1) {
		sum += stoull((*s).substr(i, 1));
	}
	
	return sum;
}

extern uint64_t sumOfVector(vector<uint64_t> &v)
{
    uint64_t sum = 0;

    for (uint64_t i : v) {
        sum += i;
    }

    return sum;
}

extern uint64_t sumOfSet(set<uint64_t> &s)
{
    uint64_t sum = 0;

    for (uint64_t i : s) {
        sum += i;
    }

    return sum;
}

extern Factor factorInteger(uint64_t i)
{
    for (uint64_t a = 2; a < i; a += 1) {
        if (i % a == 0) { // divisible

            // return factors
            return (Factor) {a, i / a};

        }
    }

    return (Factor) {0, 0};
}

extern bool isFactorPrime(Factor f)
{
	return (f.x == 0 && f.y == 0);
}

extern bool isPrime(uint64_t n)
{
    if (n == 0 || n == 1) {

        return false;

    } else if (n == 2) {

        return true;

    } else {

        if (n % 2 == 0) { // if i is divisible by 2 and is not equal to 2, it is not prime
            return false;
        }

        for (uint64_t x = 3; x <= sqrt(n); x += 2) { // only check odds

            if (n % x == 0) {
                return false;
            }

        }

        return true;

    }
}

extern uint64_t numberOfDivisors(uint64_t n)
{
    if (n > 1) {

        uint64_t divisors = 0;

        for (uint64_t x = 1; x <= sqrt(n); x += 1) {

            if (n % x == 0) {

                divisors += 1;
                if (n / x != x) { // dont add perfect squares
                    divisors += 1;
                }

            }

        }

        return divisors;

    } else {

        return (n == 0) ? 0 : 1;

    }
}

extern uint64_t nextCollatzInt(uint64_t i)
{
    if (i % 2 == 0) {
        return i / 2;
    } else {
        return (3 * i) + 1;
    }
}

extern cpp_int nCr(cpp_int n, cpp_int r)
{
	cpp_int nFact = factorial_cpp_int(n);
	cpp_int rFact = factorial_cpp_int(r);
	cpp_int nrFact = factorial_cpp_int(n - r);
	
	return nFact / (rFact * nrFact);
}

extern pyramid pyramidFromFile(string file)
{
    ifstream fileStream = readFile(file);
    pyramid p;

    if (fileStream) {

        string line;
        while (getline(fileStream, line, '\n')) { // iterate each line

            pyramidRow pRow;

            istringstream buf(line);
            istream_iterator<uint> beg(buf), end;
            vector<uint> numbers(beg, end);

            for(uint number: numbers) { // individual numbers
                pRow.push_back(number);
            }

            p.push_back(pRow);

        }

    }

    return p;
}

extern uint64_t pyramid_SumOfMaxPath(pyramid p)
{
	if (p.size() == 0) {
		return 0;
	}
	
	while (p.size() > 1) {

        // pop both bottom rows
        pyramidRow pRow = p.back();
        p.pop_back();
        pyramidRow pParentRow = p.back();
        p.pop_back();

        // calculate new bottom row and push back to stack
        // sets each parentRow value to the larger sum of itself and its children
        for (uint x = 0; x < (uint)pParentRow.size(); x += 1) {

            uint64_t leftChild = pRow[x];
            uint64_t rightChild = pRow[x + 1];

            pParentRow[x] += max(leftChild, rightChild); // add parent and larger value of its children

        }

        p.push_back(pParentRow);

    }

    return p.back().front();
}

extern void printPyramid(pyramid p)
{
    for (pyramidRow pRow : p) {
        for (uint64_t num : pRow) {
            printf("%llu ", num);
        }

        printf("\n");

    }
}

extern vector<uint64_t> circularVariations(uint64_t n)
{
    vector<uint64_t> iDigits;

    uint64_t _n = n;

    while (_n != 0) {

        iDigits.insert(iDigits.begin(), _n % 10);
        _n /= 10;

    }

    vector<uint64_t> circularVariations;

    for (uint x = 0; x < iDigits.size(); x += 1) { // move last digit to front

        uint64_t lastDigit = iDigits.back();
        iDigits.pop_back();
        iDigits.insert(iDigits.begin(), lastDigit);

        uint64_t digitToInt = 0; // convert the vector of digits back into an integer
        for (uint y = 0; y < iDigits.size(); y += 1) {
            digitToInt += iDigits[iDigits.size() - y - 1] * pow(10, y);
        }

        circularVariations.push_back(digitToInt);

    }

    return circularVariations;
}

extern double quadraticSolveSolveDescriminant(quadratic q)
{
    return (q.b * q.b) - (4.0 * q.a * q.c);
}

extern quadraticRoots quadraticSolveRoots(quadratic q)
{
    int64_t descriminant = quadraticSolveSolveDescriminant(q);

    if (descriminant < 0) {
        return {0, 0};
    }

    double numeratorAdd = -q.b + sqrt(descriminant);
    double numeratorSubtract = -q.b - sqrt(descriminant);
    double denomenator = 2.0 * q.a;

    return {numeratorAdd / denomenator, numeratorSubtract / denomenator};
}

extern int64_t triangleForN(int64_t n)
{
    uint64_t Tn = n * (n + 1);
    Tn /= 2;
    return Tn;
}

extern int64_t nForTriangle(int64_t Tn)
{
    quadratic q = {1, 1, (-2 * Tn)};
    quadraticRoots roots = quadraticSolveRoots(q);

    double largerRoot = max(roots.x, roots.y);

    if (largerRoot - (int64_t)largerRoot == 0) { // whole number
        return largerRoot;
    }

    return 0;
}

extern int64_t pentagonalForN(int64_t n)
{
    uint64_t Pn = n * ( (3 * n) - 1 );
    Pn /= 2;
    return Pn;
}

extern int64_t nForPentagonal(int64_t Pn)
{
    quadratic q = {3, -1, (-2 * Pn)};
    quadraticRoots roots = quadraticSolveRoots(q);

    double largerRoot = max(roots.x, roots.y);

    if (largerRoot - (int64_t)largerRoot == 0) { // whole number
        return largerRoot;
    }

    return 0;
}

extern int64_t hexagonalForN(int64_t n)
{
    uint64_t Hn = n * ( (2 * n) - 1 );
    return Hn;
}

extern int64_t nForHexagonal(int64_t Hn)
{
    quadratic q = {2, -1, (-1 * Hn)};
    quadraticRoots roots = quadraticSolveRoots(q);

    double largerRoot = max(roots.x, roots.y);

    if (largerRoot - (int64_t)largerRoot == 0) { // whole number
        return largerRoot;
    }

    return 0;
}

extern int64_t heptagonalForN(int64_t n)
{
    uint64_t Hn = n * ( (5 * n) - 3 );
    Hn /= 2;
    return Hn;
}

extern int64_t nForHeptagonal(int64_t Hn)
{
    if (Hn == 0) {

    }
    assert(false);
}

extern int64_t octagonalForN(int64_t n)
{
    uint64_t On = n * ( (3 * n) - 2 );
    return On;
}

extern int64_t nForOctagonal(int64_t On)
{
    if (On == 0) {

    }
    assert(false);
}

/**
 *  Calculate the proper divisors of a number (all divisors exluding the number itself)
 *
 *  @param i
 *
 *  @return vector containing proper divisors
 */
extern properDivisors calculateProperDivisors(uint64_t n)
{
    vector<uint64_t> pd;
	pd.push_back(1);

    for (uint64_t x = 2; x <= sqrt(n); x += 1) {
		
		uint64_t n_x = n / x;
		
        if (n_x * x == n) {
            pd.push_back(x);
            if (n_x != x) { // dont add same multiple twice
                pd.push_back(n_x);
            }
        }
    }

    return pd;
}

extern numberType getNumberType(uint64_t n)
{
	auto pd = calculateProperDivisors(n);
    uint64_t x = sumOfVector(pd);

    if (x < n) {
        return NumberType_Deficient;
    } else if (x > n) {
        return NumberType_Abundant;
    } else {
        return NumberType_Perfect;
    }
}

extern uint64_t concatanate(uint64_t a, uint64_t b)
{
    uint64_t result = b;
    uint64_t resultDigits = numberOfDigits(result);
    
    while (a > 0) {
        
        uint64_t aDigit = a % 10;
        
        result += aDigit * pow(10, resultDigits);
        resultDigits += 1;
        
        a /= 10;
        
    }
    
    return result;
}

extern bool isPandigital(uint64_t i, uint64_t n)
{
    set<uint64_t> *temp = new set<uint64_t>();
    
    while (i > 0) {
		if (i % 10 != 0) { // don't add zeros
			temp->insert(i % 10);
		}
        i /= 10;
    }
    
    bool isPandigital = (temp->size() == n); // size must equal n. It won't if there are multiple similar digits (set)
    
    if (isPandigital) {
        
        for (uint64_t x = 1; x <= n; x += 1) { // remove each digit
            temp->erase(x);
        }
        
        isPandigital = (temp->size() == 0);
        
    }
    
    temp->clear();
    delete temp;
    
    return isPandigital;
}

extern bool isPandigital(uint64_t i, uint64_t a, uint64_t b)
{
	set<uint64_t> *digits = new set<uint64_t>();
	
	while (i > 0) {
		digits->insert(i % 10);
		i /= 10;
	}
	
	// n = number of digits
	// lower and upper bounds match
	uint64_t n = (b + 1) - a;
	bool isPandigital = digits->size() == n && *digits->begin() == a && *digits->rbegin() == b;
	
	if (isPandigital) {
		
		for (uint64_t x = a; x <= b; x += 1) { // remove each digit
			digits->erase(x);
		}
		
		isPandigital = (digits->size() == 0);
		
	}
	
	digits->clear();
	delete digits;
	
	return isPandigital;
}

extern uint64_t fibonacci(uint64_t n)
{
	if (n < 2) {
		return n;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

extern string englishRepresentationOfNumber(uint64_t n)
{
	string returnVal = "";
	
	if (n < 20) {
		
		returnVal =  ((NSString *)@[
									@"zero", @"one", @"two", @"three", @"four",
									@"five", @"six", @"seven", @"eight", @"nine",
									@"ten", @"eleven",  @"twelve", @"thirteen", @"fourteen",
									@"fifteen", @"sixteen", @"seventeen", @"eighteen", @"nineteen"
									][n]).UTF8String;
		
	} else if (n >= 20 && n < 100) {
		
		uint64_t tensDigit = n / 10;
		
		if (tensDigit == 2) {
			returnVal = "twenty";
		} else if (tensDigit == 3) {
			returnVal = "thirty";
		} else if (tensDigit == 4) {
			returnVal = "forty";
		} else if (tensDigit == 5) {
			returnVal = "fifty";
		} else if (tensDigit == 6) {
			returnVal = "sixty";
		} else if (tensDigit == 7) {
			returnVal = "seventy";
		} else if (tensDigit == 8) {
			returnVal = "eighty";
		} else if (tensDigit == 9) {
			returnVal = "ninety";
		} else {
			return returnVal;
		}
		
		uint64_t onesDigit = n % 10;
		
		if (onesDigit > 0) {
			returnVal += englishRepresentationOfNumber(onesDigit);
		}
		
	} else if (n >= 100 && n < 1000) {
		
		uint64_t hundredsDigit = n / 100;
		returnVal = englishRepresentationOfNumber(hundredsDigit) + "hundred";
		
		if (n % 100 != 0) {
			returnVal += "and" + englishRepresentationOfNumber(n % 100);
		}
		
	} else if (n >= 1000) {
		
		uint64_t thousandsDigit = n / 1000;
		returnVal = englishRepresentationOfNumber(thousandsDigit) + "thousand";
		
		if (n % 1000 != 0) {
			returnVal += englishRepresentationOfNumber(n % 1000);
		}
		
	}
	
	return returnVal;
}

extern bool isIncreasingNumber(uint64_t n)
{
	string _n = to_string(n);
	
	for (auto itr = _n.begin(); itr + 1 != _n.end(); advance(itr, 1)) {
		if (*itr > *next(itr)) {
			return false;
		}
	}
	
	return true;
}

extern bool isDecreasingNumber(uint64_t n)
{
	string _n = to_string(n);
	
	for (auto itr = _n.begin(); itr + 1 != _n.end(); advance(itr, 1)) {
		if (*itr < *next(itr)) {
			return false;
		}
	}
	
	return true;
}

extern bool isBouncyNumber(uint64_t n)
{
	return (!isIncreasingNumber(n) && !isDecreasingNumber(n));
}

extern void reduceFraction(uint64_t &a, uint64_t &b)
{
	uint64_t _gcd = gcd(a, b);
	
	a /= _gcd;
	b /= _gcd;
}

extern pair<uint64_t, uint64_t> reduceFraction2(uint64_t a, uint64_t b)
{
	uint64_t _gcd = gcd(a, b);
	
	return { a / _gcd, b / _gcd };
}

extern uint64_t gcd(uint64_t a, uint64_t b)
{
	if (b == 0 ) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

extern bool isLychrel(uint64_t n)
{
	cpp_int _n(n);
	
	for (uint64_t i = 0; i < 50; i += 1) {
		
		string reverseN(_n.str());
		reverse(begin(reverseN), end(reverseN));
		while (reverseN[0] == '0') { // Trim leading 0's for cpp_int conversion
			reverseN = reverseN.substr(1, reverseN.length() - 1);
		}
		
		_n += cpp_int(reverseN);
		
		if (isPalindrome(_n.str())) {
			return false;
		}
		
	}
	
	return true;
}

extern uint64_t reverseNumber(uint64_t n)
{
	uint64_t reverseN = 0;
	
	while (n > 0) {
		reverseN *= 10;
		reverseN += n % 10;
		n /= 10;
	}
	
	return reverseN;
}

extern uint64_t changeBase(uint64_t n, uint64_t base)
{
	uint64_t returnVal = 0;
	uint64_t count = 1;
	
	while (n > 0) {
		uint64_t remainder = n % base;
		n = floor(n / base);
		returnVal += remainder * count;
		count *= 10;
	}
	
	return returnVal;
}




