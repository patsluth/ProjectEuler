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
#include "hashMap.h"

#include <boost/foreach.hpp>

#include <algorithm>    // std::find
#include <vector>       // std::vector

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_60 : public problem_base
{
    //set<uint64_t> primeCache;
    vector<uint64_t> primeCache2;

    string desiredAnswer()
    {
        return "26033";
    }

    //TODO: RENAME THIS BTICH
    bool setPastsTest(set<uint64_t> *s)
    {
//       if (s.size() < 4){
//           return false;
//       }

        // test current prime set
        for (uint64_t primeAIndex : *s) {
            for (uint64_t primeBIndex : *s) {
                
                if (primeAIndex != primeBIndex) {
                    
                    if (primeAIndex == 1 && primeBIndex == 2){
                        
                    }
                    
                    
                    
                    uint64_t concat_AB = concatanate(primeCache2[primeAIndex], primeCache2[primeBIndex]);
                    
                    
                    //                    if (!isPrimeFast(concat_AB)){
                    //                        return false;
                    //                    }
                    
                    if (primeCache2.back() < concat_AB) { // to big
                        return false;
                    }
                    
                    auto searchAB = std::find(primeCache2.begin(), primeCache2.end(), concat_AB);
                    if (searchAB == primeCache2.end()) { //not found
                        return false;
                    }
                    
                    
                    
                    
                    
                    uint64_t concat_BA = concatanate(primeCache2[primeBIndex], primeCache2[primeAIndex]);
                    
                    if (primeCache2.back() < concat_BA) { // to big
                        return false;
                    }
                    
                    
                    auto searchBA = std::find(primeCache2.begin(), primeCache2.end(), concat_BA);
                    if (searchBA == primeCache2.end()) { //not found
                        return false;
                    }
                    
                   
                    
                    
                    
                    
                }


            }
        }

        return true;
    }

    set<uint64_t> *findNext(set<uint64_t> *current)
    {
        if (current->size() == 0) {
            return current;
        }
        
        //uint64_t lastIndex = *current->rbegin();
        
        //we dont need to test all 100000, we just have that many so we can quickly check the concatanations
        //for (uint64_t x = lastIndex + 1; x < lastIndex + 6000; x++) {
        for (uint64_t x = 0; x < primeCacheSize; x++) {
            
            uint64_t prevSize = current->size();
            current->insert(x);
            
            if (prevSize != current->size()) { //added element
                
                
                
                if (current->size() < 5){
                
                    uint64_t cursum = 0;
                    for (uint64_t primeINDEX : *current){
                        cursum += primeCache2[primeINDEX];
                    }
                    if (cursum > 27000){
                        cout << "SKIPPING" << endl;
                        return current;
                    }
                    
                }
                
                
                
                
                
                if (!setPastsTest(current)){
                    current->erase(x);
                } else {
                    
                    if (current->size() == 5){
                        
                        return current;
                        
                    }
                    
                    
                    
                    
                    
                    return findNext(current);
                    
                }
                
            }
            
        }
        
        return current;
    }
    
    
    
    uint64_t primeCacheSize = 200000;

    void subrun()
    {
        uint64_t n = 0;
        uint64_t curPrime = 0;
        
        hashMap hash;
        
        while (n < primeCacheSize){
            if (isPrimeFast(curPrime)){
                primeCache2.push_back(curPrime);
                if (n < 500)
                    //hash.addValueToSetForKey(n, n);
                n++;
            }
            
            curPrime++;
        }
        n = 0;
        curPrime = 0;
        
        while (n < 500){
            
            for (uint64_t x = 0; x < hash.size(); x++) {
                
                
                uint64_t prevSize = hash.setForKey(x)->size();
                //hash.addValueToSetForKey(n, x);
                
                if (prevSize != hash.setForKey(x)->size()){
                    
                    if (!setPastsTest(hash.setForKey(x))){
                        hash.setForKey(x)->erase(n);
                    } else {
                        
                        if (hash.setForKey(x)->size() > 3){
                            cout << hash.setForKey(x)->size() << endl;
                        }
                        
                    }
                    
                }
                
                
            }
            
            n++;
            
        }
        
        
        
        
        
//        while (true) {
//        
//            for (uint64_t x = 0; x < primeCache2.size(); x++) {
//                
//                for (uint64_t y = 0; y < primeCache2.size(); y++) {
//                    
//                    
//                    if (x != y) {
//                        
//                        
//                        uint64_t prevSize = hash.setForKey(x)->size();
//                        hash.addValueToSetForKey(y, x);
//                        
//                        if (prevSize != hash.setForKey(x)->size()){
//                            
//                            if (!setPastsTest(hash.setForKey(x))){
//                                hash.setForKey(x)->erase(y);
//                            } else {
//                                
//                                if (hash.setForKey(x)->size() > 3){
//                                    cout << "H";
//                                }
//                                
//                            }
//                            
//                        }
//                        
//                        
//                    }
//                    
//                    
//                    
//                }
//                
//            }
//            
//        }
        
        
        cout << "END: " << hash.size() << endl;
        
        uint64_t startIndex = 0;
        while (true) {
            set<uint64_t> sTemp = { startIndex };
            set<uint64_t> *x = findNext(&sTemp);
            
            if (x->size() == 5 ){
                cout << "5!!! ->";
                uint64_t cursum = 0;
                for (uint64_t primeINDEX : *x){
                    cout << " " << primeCache2[primeINDEX] << " ";
                    cursum += primeCache2[primeINDEX];
                }
                cout << "SUM: " << cursum << endl;
            }
            
            startIndex++;
            
            if (startIndex > 100000){
                break;
            }
        }

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

        return result;
    }

};




