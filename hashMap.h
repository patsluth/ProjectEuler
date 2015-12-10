//
//  hashMap.cpp
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-12-09.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

#ifndef hashMap_h
#define hashMap_h

#include <stdio.h>
#include <set>
#include <map>

using namespace std;





class hashMap
{
    
private:
    
    map<uint64_t, set<uint64_t>> data;
    
public:
    
    uint64_t size()
    {
        return this->data.size();
    }
    
    set<uint64_t> *setForKey(uint64_t key)
    {
        if (this->data.count(key) == false) {
            this->data[key] = {};
        }
        
        return &this->data[key];
    }
    
};

#endif /* hashMap_h */



