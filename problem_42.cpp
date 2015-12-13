//
//  problem_42.h
//  Coded triangle numbers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

using namespace std;





class problem_42 : public problem_base
{
    
    string desiredAnswer()
    {
        return "162";
    }
    
    void subrun()
    {
        ifstream fileStream = readFile("p042_words.txt");
        
        if (fileStream) {
            
            string word;
            uint64_t triangleWordCount = 0;
            
            while (getline(fileStream, word, ',')) {
                
                if (nForTriangle(wordToNumber(word)) != 0) { //word number is a triangle word
                    triangleWordCount++;
                }
                
            }
            
            calculatedAnswer << triangleWordCount;
            
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




