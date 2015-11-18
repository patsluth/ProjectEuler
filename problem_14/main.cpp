//
//  main.cpp
//  problem_14
//  Longest Collatz sequence
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;





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
uint64_t getNextInt(uint64_t i)
{
    if (i % 2 == 0){
        return i / 2;
    } else {
        return (3 * i) + 1;
    }
}

int main(int argc, const char * argv[])
{
    vector<uint64_t> greatestSequence;
    
    for (uint64_t x = 1; x < 1000000; x++){
        
        vector<uint64_t> currentSequence;
        currentSequence.push_back(x);
        
        while (currentSequence.back() != 1){
            currentSequence.push_back(getNextInt(currentSequence.back()));
        }
        
        if (currentSequence.size() > greatestSequence.size()){
            greatestSequence = currentSequence;
        }
        
    }
    
    printf("The Collatz starting number less than 1 million that produces the longest chain is [%llu]\n\n", greatestSequence.front());
    
    return 0;
}




