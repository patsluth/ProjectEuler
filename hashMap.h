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





template <class K, class V>
class hashMap
{
    
private:
    
    map<K, V> data;
    
public:
    
    uint64_t size()
    {
        return this->data.size();
    }
    
    typename map<K, V>::iterator begin()
    {
        return this->data.begin();
    }
    
    typename map<K, V>::iterator rbegin()
    {
        return this->data.rbegin();
    }
    
    typename map<K, V>::iterator end()
    {
        return this->data.end();
    }
    
    V *valueForKey(K key)
    {
        if (this->data.count(key) == false) {
            this->data[key] = *new V();
        }
        
        return &this->data[key];
    }
    
};

#endif /* hashMap_h */



