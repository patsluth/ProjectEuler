//
//  problem_61.h
//  Cyclical figurate Numbers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

#include <boost/foreach.hpp>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;




class hashMap
{
    
public:
    
    map<uint64_t, set<uint64_t>> data;
    
    set<uint64_t> valueForKey(uint64_t key)
    {
        if (this->data.count(key) == false) {
            this->data[key] = {};
        }
        
        return this->data[key];
    }
    
    void appendValueForKey(uint64_t key, uint64_t value)
    {
        if (this->data.count(key) == true) {
            this->data[key].insert(value);
        } else {
            this->data[key] = {value};
        }
    }
    
};




class problem_61 : public problem_base
{
    
    string desiredAnswer()
    {
        return "28684";
    }
    
    void subrun()
    {
        set<uint64_t> triangles;
        set<uint64_t> squares;
        set<uint64_t> pentagonals;
        set<uint64_t> hexagonals;
        set<uint64_t> heptagonals;
        set<uint64_t> octagonals;
        
        hashMap frontDigitMap;
        
        for (uint64_t n = 0; ; n++) { //cache
            
            uint64_t triangle = triangleForN(n);
            uint64_t square = (n * n);
            uint64_t pentagonal = pentagonalForN(n);
            uint64_t hexagonal = hexagonalForN(n);
            uint64_t heptagonal = heptagonalForN(n);
            uint64_t octagonal = octagonalForN(n);
            
            
            
            if (triangle > 999 && triangle < 10000) {
                
                triangles.insert(triangle);
                
                uint64_t frontDigits = triangle / 100;
                frontDigitMap.appendValueForKey(frontDigits, triangle);
                
            }
            
            if (square > 999 && square < 10000) {
                
                squares.insert(square);
                
                uint64_t frontDigits = square / 100;
                frontDigitMap.appendValueForKey(frontDigits, square);
                
            }
            
            if (pentagonal > 999 && pentagonal < 10000) {
                
                pentagonals.insert(pentagonal);
                
                uint64_t frontDigits = pentagonal / 100;
                frontDigitMap.appendValueForKey(frontDigits, pentagonal);
                
            }
            
            if (hexagonal > 999 && hexagonal < 10000) {
                
                hexagonals.insert(hexagonal);
                
                uint64_t frontDigits = hexagonal / 100;
                frontDigitMap.appendValueForKey(frontDigits, hexagonal);
                
            }
            
            if (heptagonal > 999 && heptagonal < 10000) {
                
                heptagonals.insert(heptagonal);
                
                uint64_t frontDigits = heptagonal / 100;
                frontDigitMap.appendValueForKey(frontDigits, heptagonal);
                
            }
            
            if (octagonal > 999 && octagonal < 10000) {
                
                octagonals.insert(octagonal);
                
                uint64_t frontDigits = octagonal / 100;
                frontDigitMap.appendValueForKey(frontDigits, octagonal);
                
            }
            
            
            
            if (triangle > 9999 && square > 9999 &&
                pentagonal > 9999 && hexagonal > 9999 &&
                heptagonal > 9999 && octagonal > 9999) {
                break;
            }
            
        }
        
   
        
        
        
        BOOST_FOREACH(auto currentDigitSet, frontDigitMap.data) {
            
            BOOST_FOREACH(auto n1, currentDigitSet.second) {
                
                uint64_t backDigits = n1 % 100;
                auto nextDigitSet = frontDigitMap.valueForKey(backDigits);
                
                BOOST_FOREACH(auto n2, nextDigitSet) {
                    
                    uint64_t backDigits = n2 % 100;
                    auto nextDigitSet = frontDigitMap.valueForKey(backDigits);
                    
                    BOOST_FOREACH(auto n3, nextDigitSet) {
                        
                        uint64_t backDigits = n3 % 100;
                        auto nextDigitSet = frontDigitMap.valueForKey(backDigits);
                        
                        BOOST_FOREACH(auto n4, nextDigitSet) {
                            
                            uint64_t backDigits = n4 % 100;
                            auto nextDigitSet = frontDigitMap.valueForKey(backDigits);
                            
                            BOOST_FOREACH(auto n5, nextDigitSet) {
                                
                                uint64_t backDigits = n5 % 100;
                                auto nextDigitSet = frontDigitMap.valueForKey(backDigits);
                                
                                BOOST_FOREACH(auto n6, nextDigitSet) {
                                    
                                    uint64_t backDigits = n6 % 100;
                                    auto nextDigitSet = frontDigitMap.valueForKey(backDigits);
                                    
                                    if (backDigits == currentDigitSet.first) { //check the front of the loop
                                        
                                        //vector<uint64_t> curChain = {n1, n2, n3, n4, n5, n6};
                                        set<uint64_t> curChainCopy; //remove duplicates
                                        
                                        curChainCopy.insert(n1);
                                        curChainCopy.insert(n2);
                                        curChainCopy.insert(n3);
                                        curChainCopy.insert(n4);
                                        curChainCopy.insert(n5);
                                        curChainCopy.insert(n6);
                                        
                                        if (curChainCopy.size() == 6) {
                                            
                                            bool hasTri, hasSqr, hasPent, hasHex, hasHept, hasOct;
                                            hasTri = hasSqr = hasPent = hasHex = hasHept = hasOct = false;
                                            
                                            for (uint64_t i : curChainCopy) {
                                                
                                                if (!hasOct && octagonals.count(i) == 1) {
                                                    hasOct = true;
                                                } else if (!hasHept && heptagonals.count(i) == 1) {
                                                    hasHept = true;
                                                } else if (!hasHex && hexagonals.count(i) == 1) {
                                                    hasHex = true;
                                                } else if (!hasPent && pentagonals.count(i) == 1) {
                                                    hasPent = true;
                                                } else if (!hasSqr && squares.count(i) == 1) {
                                                    hasSqr = true;
                                                } else if (!hasTri && triangles.count(i) == 1) {
                                                    hasTri = true;
                                                }
                                            }
                                            
                                            if (hasTri && hasSqr && hasPent && hasHex && hasHept && hasOct) {
                                                //FOUND IT!
                                                calculatedAnswer << ( n1 + n2 + n3 + n4 + n5 + n6 );
                                                return;
                                            }
                                            
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
    
    void tdd()
    {
        //TODO: MOVE
        
        assert(heptagonalForN(1) == 1);
        assert(heptagonalForN(2) == 7);
        assert(heptagonalForN(3) == 18);
        assert(heptagonalForN(4) == 34);
        assert(heptagonalForN(5) == 55);
        
        assert(octagonalForN(1) == 1);
        assert(octagonalForN(2) == 8);
        assert(octagonalForN(3) == 21);
        assert(octagonalForN(4) == 40);
        assert(octagonalForN(5) == 65);
    }
    
};




