//
//  Problem_61.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"

#import "hashMap.h"

#import <boost/foreach.hpp>





@interface Problem_61 : ProblemBase
{
}

@end





@implementation Problem_61

- (id)solveProblem
{
	set<uint64_t> triangles;
	set<uint64_t> squares;
	set<uint64_t> pentagonals;
	set<uint64_t> hexagonals;
	set<uint64_t> heptagonals;
	set<uint64_t> octagonals;
	
	hashMap<uint64_t, set<uint64_t>> frontDigitMap;
	
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
			frontDigitMap.valueForKey(frontDigits)->insert(triangle);
			
		}
		
		if (square > 999 && square < 10000) {
			
			squares.insert(square);
			
			uint64_t frontDigits = square / 100;
			frontDigitMap.valueForKey(frontDigits)->insert(square);
			
		}
		
		if (pentagonal > 999 && pentagonal < 10000) {
			
			pentagonals.insert(pentagonal);
			
			uint64_t frontDigits = pentagonal / 100;
			frontDigitMap.valueForKey(frontDigits)->insert(pentagonal);
			
		}
		
		if (hexagonal > 999 && hexagonal < 10000) {
			
			hexagonals.insert(hexagonal);
			
			uint64_t frontDigits = hexagonal / 100;
			frontDigitMap.valueForKey(frontDigits)->insert(hexagonal);
			
		}
		
		if (heptagonal > 999 && heptagonal < 10000) {
			
			heptagonals.insert(heptagonal);
			
			uint64_t frontDigits = heptagonal / 100;
			frontDigitMap.valueForKey(frontDigits)->insert(heptagonal);
			
		}
		
		if (octagonal > 999 && octagonal < 10000) {
			
			octagonals.insert(octagonal);
			
			uint64_t frontDigits = octagonal / 100;
			frontDigitMap.valueForKey(frontDigits)->insert(octagonal);
			
		}
		
		
		
		if (triangle > 9999 && square > 9999 &&
			pentagonal > 9999 && hexagonal > 9999 &&
			heptagonal > 9999 && octagonal > 9999) {
			break;
		}
		
	}
	
	
	
	
	auto itr = frontDigitMap.begin();
	
	while (itr != frontDigitMap.end()) {
		
		BOOST_FOREACH(auto n1, (*itr).second) {
			
			uint64_t backDigits = n1 % 100;
			auto nextDigitSet = *frontDigitMap.valueForKey(backDigits);
			
			BOOST_FOREACH(auto n2, nextDigitSet) {
				
				uint64_t backDigits = n2 % 100;
				auto nextDigitSet = *frontDigitMap.valueForKey(backDigits);
				
				BOOST_FOREACH(auto n3, nextDigitSet) {
					
					uint64_t backDigits = n3 % 100;
					auto nextDigitSet = *frontDigitMap.valueForKey(backDigits);
					
					BOOST_FOREACH(auto n4, nextDigitSet) {
						
						uint64_t backDigits = n4 % 100;
						auto nextDigitSet = *frontDigitMap.valueForKey(backDigits);
						
						BOOST_FOREACH(auto n5, nextDigitSet) {
							
							uint64_t backDigits = n5 % 100;
							auto nextDigitSet = *frontDigitMap.valueForKey(backDigits);
							
							BOOST_FOREACH(auto n6, nextDigitSet) {
								
								uint64_t backDigits = n6 % 100;
								auto nextDigitSet = *frontDigitMap.valueForKey(backDigits);
								
								if (backDigits == (*itr).first) { //check the front of the loop
									
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
											return @(n1 + n2 + n3 + n4 + n5 + n6); // FOUND IT!
										}
										
									}
									
								}
							}
						}
					}
				}
			}
		}
		
		advance(itr, 1);
		
	}
	
	return nil;
}

@end





