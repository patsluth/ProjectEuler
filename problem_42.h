//
//  problem_42.h
//  Coded triangle numbers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iterator>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_42 : public problem_base
{
    
    string desiredAnswer()
    {
        return "162";
    }
    
    void subrun()
    {
        string file = "p042_words.txt";
        
        ifstream fileStream(file);
        
        if (fileStream) {
            
            string word;
            uint64_t triangleWordCount = 0;
            
            while (getline(fileStream, word, ',')) {
                
                if (nForTriangle(wordToNumber(word)) != 0) { //word number is a triangle word
                    triangleWordCount++;
                }
                
            }
            
            calculatedAnswer << triangleWordCount;
            
        } else {
            
            fprintf(stderr, "Error reading %s\n", file.c_str());
            
        }
    }
    
    void tdd()
    {
        assert(wordToNumber("SKY") == 55);
    }
    
    uint64_t wordToNumber(string w)
    {
        uint64_t returnValue = 0;
        
        for (char c : w) {
            
            uint64_t cIndex = toupper(c); //upper case letters 65-90 inclusive
            
            if (cIndex > 64 && cIndex < 91) {
                returnValue += cIndex - 64;
            }
        }
        
        return returnValue;
    }
    
};




