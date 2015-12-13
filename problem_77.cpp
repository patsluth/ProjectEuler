//
//  problem_77.h
//  Prime summations
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_77 : public problem_base
{

    string desiredAnswer()
    {
        return "71";
    }
    
//    uint64_t test(uint64_t base, uint64_t i)
//    {
//        if (i > 2) {
//            
////            // 1st million primes
////            set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1);
////            
////            auto itr = millionPrimes.begin(); // reverse iterator. Since we are looking for the largest, the first prime to pass is the answer
////            
////            while (*itr < i) {
////                
////                uint64_t difference = i - *itr;
////                
////                if (primes::sharedPrimes()->isPrime(difference)) {
////                    
////                    if (
////                    cout << i << " - " << *itr << " = " << difference << ";" << endl;
////                    test(base, difference);
////                }
////                
////                advance(itr, 1);
////            }
////            
////            cout << endl;
////            return i;
//            
//        } else {
//           
//            if (i == 2) {
//                return 1;
//            } else {
//                return 0;
//            }
//            
//        }
//    }
    
//    uint64_t test2(uint64_t i)
//    {
//        if (i < 2) {
//            return 0;
//        } else if (i == 2 || i == 3) {
//            return 1;
//        } else {
//            
//            // 1st million primes
//            set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1);
//            
//            vector<pair<uint64_t, uint64_t>> sumSets;
//            auto itr = millionPrimes.begin();
//            
//            while (*itr < i) {
//                
//                uint64_t a = i - *itr;
//                uint64_t b = i - a;
//                
//                sumSets.push_back( {a, b} );
//                
////                if (primes::sharedPrimes()->isPrime(a) && primes::sharedPrimes()->isPrime(b)) {
////                    return 1 + test2(a) + test2(b);
////                } else {
////                    return test2(a) + test2(b);
////                }
//                
//                //cout << "(" << a << ", " << b << ") ";
//                advance(itr, 1);
//                
//            }
//            
//            for (auto p : sumSets) {
//                cout << "(" << p.first << ", " << p.second << ") ";
//                return test2(p.first) + test2(p.second);
//            }
//            
//            cout << endl;
//            
////            for (auto p : sumSets) {
////                if (!primes::sharedPrimes()->isPrime(p.first))
////                    test2(p.first);
////                cout << endl;
////                if (!primes::sharedPrimes()->isPrime(p.second))
////                    test2(p.second);
////            }
//            
//        }
//        
//        return 0;
//    }
    
    
    
    
    vector<vector<uint64_t>> test2(uint64_t i)
    {
        if (i > 3) {
            
            // 1st million primes
            set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1);
            auto itr = millionPrimes.begin();
            
            
            vector<vector<uint64_t>> vv;
            
            
            
            while (*itr < i) {
                
                uint64_t a = i - *itr;
                uint64_t b = i - a;

                
                vector<uint64_t> v1 = { { a, b } };
                vector<vector<uint64_t>> v2 = test2(a);
                v2.push_back(v1);
                vector<vector<uint64_t>> v3 = test2(b);
                
                for (auto aut2 : v2) {
                    vv.push_back(aut2);
                }
                for (auto aut3 : v3) {
                    vv.push_back(aut3);
                }
                
                advance(itr, 1);
                
            }
            
            return vv;
            
        } else {
            return { { i } };
        }
    }
    
        
//        vector<vector<uint64_t>> xxxx;
//        xxxx.push_back(*s);
//        
//        // 1st million primes
//        set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1);
//        auto sItr = s->begin();
//        
//        while (sItr != s->end()) {
//            
//            auto primeItr = millionPrimes.begin();
//            
//            while (*primeItr < *sItr) {
//                
//                uint64_t a = *sItr - *primeItr;
//                uint64_t b = *sItr - a;
//                
//                cout << "(" << a << ", " << b << ") " << endl;
//                
//                if (a < 2 || b < 2) {
//                    break;
//                } else {
//                    
//                    s->erase(sItr);
//                    s->push_back(a);
//                    s->push_back(b);
//                    
//                    //cout << tits.size();
//                    auto t = *s;
//                    vector<vector<uint64_t>> xxxxCopy = test2(&t);
//                    
//                    for (auto y : xxxxCopy){
//                        xxxx.push_back(y);
//                    }
//                    
//                    return xxxx;
//                    
//                    //return xxxxCopy;
//                    
//                }
////                
////                cout << "(" << a << ", " << b << ") ";
//                advance(primeItr, 1);
//                
//            }
//            
//            advance(sItr, 1);
//            
//        }
//        
//        return xxxx;
   // }
    
    
    
    
    void subrun()
    {
       // vector<uint64_t> ss = { 10, 0 };
        auto b = test2(10);
        
        for (auto bb : b){
            if (sumOfVector(&bb) == 10) {
                for (auto bbb : bb){
                    cout << bbb << " ";
                }
                cout << endl;
            }
        }
        
        cout << b.size();
        
//        test2(8);
//        cout << endl;
//        
//        test2(6);
//        cout << endl;
//        
//        test2(4);
//        cout << endl;
        
        
    }
    
    void tdd()
    {
    }

};
