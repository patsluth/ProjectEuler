//
//  hashMap.cpp
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-12-09.
//  Copyright © 2015 Pat Sluth. All rights reserved.
//

#ifndef hashMap_h
#define hashMap_h

#import <Foundation/Foundation.h>

#import <map>

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
	
	typename map<K, V>::iterator end()
	{
		return this->data.end();
	}
	
	typename map<K, V>::reverse_iterator rbegin()
	{
		return this->data.rbegin();
	}
	
	typename map<K, V>::reverse_iterator rend()
	{
		return this->data.rend();
	}
	
	typename map<K, V>::iterator find (const K key)
	{
		return this->data.find(key);
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



