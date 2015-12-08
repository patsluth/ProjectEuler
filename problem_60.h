//
//  problem_60.h
//  Prime pair sets
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <set>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_60 : public problem_base
{
    set<uint64_t> primeCache;
    uint64_t primeCache2[100000];

    string desiredAnswer()
    {
        return "26033";
    }

//    set<uint64_t> test()
//    {
//
//
//       // while (true) {
//
//            for (uint64_t prime : primeCache) {
//
//                set<uint64_t> current = {prime};
//
//                while (true) {
//
//                    uint64_t prime22;
//
//                    for (uint64_t prime2 : primeCache) {
//
//                        uint64_t curSize = current.size();
//                        cout << curSize << endl;
//                        current.insert(prime2);
//
//                        if (curSize != current.size() && current.size() > 1){
//                            prime22 = prime2;
//                            break;
//                        }
//
//                    }
//
//                    if (setPastsTest(current) == false){
//                        current.erase(prime22);
//                    } else {
//                        if (current.size() == 4) {
//
//                        }
//                    }
//
//                }
//
//
//
//            }
//
//      //  }
//
//        return {1};
//    }

    //TODO: RENAME THIS BTICH
    bool setPastsTest(set<uint64_t> s)
    {
//       if (s.size() < 4){
//           return false;
//       }

        // test current prime set
        for (uint64_t primeA : s) {
            for (uint64_t primeB : s) {

                if (primeA != primeB) { // dont compare similar elements

                    uint64_t concat_AB = concatanate(primeA, primeB);

                    if (concat_AB > *primeCache.rbegin()){

                        //cout << *primeCache.rbegin() << endl;

                        if (isPrimeFast(concat_AB)){
                            primeCache.insert(concat_AB);
                        } else {
                            return false;
                        }
                    } else if (primeCache.count(concat_AB) == 0) {
                        return false;
                    }
                    
                    uint64_t concat_BA = concatanate(primeB, primeA);

                    if (concat_BA > *primeCache.rbegin()){
                        if (isPrimeFast(concat_BA)){
                            primeCache.insert(concat_BA);
                        } else {
                            return false;
                        }
                    } else if (primeCache.count(concat_BA) == 0) {
                        return false;
                    }

                }
            }
        }

        return true;
    }

    set<uint64_t> fiveset(set<uint64_t> current)
    {
//        if (current.size() >= 4){
//            return *current;
//        } else {
//
//            uint64_t primeIndex = 0;
//
//            if (current.size() > 0){
//                primeIndex = *current.rbegin();
//            }
//            
//            for (uint64_t x = primeIndex + 1; x < 100000; x++) {
//                
//                current.insert(x);
//                
//                if (!setPastsTest(current)){ //test failed, remove p
//                    current.erase(x);
//                } else {
//                    return fiveset(current);
//                }
//                
//            }
//
//        }
        
        return current;
    }
    
    

    void subrun()
    {
        vector<set<uint64_t>> test;
        
        uint64_t n = 0;
        uint64_t curPrime = 0;
        
        while (n < 100000){
            
            if (isPrimeFast(curPrime)){
                primeCache2[n] = curPrime;
                n++;
            }
            
            curPrime++;
            
        }
        
//        while (true) {
//            
//            set<uint64_t> temp;
//            set<uint64_t> *sssssss = &fiveset(temp);
//            
//            //cout << sssssss.size() << endl;
//            
//            if (sssssss.size() >= 4){
//                break;
//            }
//            
//        }
        


//        for (uint64_t pr = 2; pr < 1000000; pr++) {
//            if (isPrimeFast(pr)) {
//                primeCache.insert(pr);
//            }
//        }
        
        return;

        cout << "PRIMES CACHED" << endl;

        for (uint64_t p : primeCache) {
            //if (isPrimeFast(p)) {

            //if (p < 15000){

                set<uint64_t> penis;
                penis.insert(p);
                test.push_back(penis);

                for (set<uint64_t> &sss : test){

                    uint64_t x = *sss.find(p);

                    if (p > *sss.rbegin() && x != p){ //set does not contain p

                        sss.insert(p);

                        if (!setPastsTest(sss)){ //test failed, remove p
                            sss.erase(p);
                        } else {
                            if (sss.size() >= 4){

                              for (auto at : sss){
                                  cout << at << " ";
                              }
                              cout << endl;

                                cout << "SUCCESS" << endl;
                                break;
                            }
                        }

                    }
                }




            //}

        }

//        for (set<uint64_t> t : test){
//            cout << t.size() << endl;
//        }

        //test();








//        for (uint64_t prime : primeCache) {
//
//            if (prime != 3 && prime != 7 && prime != 109 && prime!= 673) {
//
//                cur.push_back(prime);
//
//                //test current prime set
//                for (uint64_t primeA : cur) {
//                    for (uint64_t primeB : cur) {
//                        if (primeA != primeB) {
//
//                            //primeA and primeB are not prime when concatenated
//                            if (primeCache.count(concatanate(primeA, primeB)) == 0 ||
//                                primeCache.count(concatanate(primeB, primeA)) == 0) {
//                                success = false;
//                            }
//
//                        }
//                    }
//                }
//
//                if (success) {
//
//                    cout << "SUCCESS" << endl;
//
//                    if (cur.size() >= 5){
//                        break;
//                    }
//
//                } else {
//
//                    cout << "FAIL " << cur.back() << endl;
//                    cur.pop_back();
//
//                }
//
//            }
//
//        }




//        for (uint64_t primeA : primeCache) {
//            for (uint64_t primeB : primeCache) {
//                if (primeA != primeB) {
//
//                    if (primeCache.count(concatanate(primeA, primeB)) != 0 &&
//                        primeCache.count(concatanate(primeB, primeA)) != 0) {
//
//                        cur.push_back(primeA);
//                        cur.push_back(primeB);
//
//                    } else {
//
//                    }
//
//                }
//            }
//            cout << cur.size() << " " << cur.size() << endl;
//        }

    }

    uint64_t concatanate(uint64_t a, uint64_t b)
    {
        uint64_t result = b;
        uint64_t resultDigits = numberOfDigits(result);

        while (a > 0) {

            uint64_t aDigit = a % 10;

            result += aDigit * pow(10, resultDigits);
            resultDigits++;

            a /= 10;

        }

        // if (result > 10000000){
        //
        // }

        return result;
    }

};




