//
//  problem_22.h
//  Names scores
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_22 : public problem_base
{
    
    string desiredAnswer()
    {
        return "871198282";
    }
    
    /**
     *  The sum of the integer value of each letter in the name * the lineNumber
     *  Ex 
     *  COLIN 3 + 15 + 12 + 9 + 14 = 53
     *  lineNumber = 938
     *  COLIN * lineNumber = 49714
     *
     *  @param s
     *
     *  @return stringScore
     */
    uint64_t nameScore(const string *name, uint64_t lineNumber)
    {
        uint64_t letterSum = 0;
        
        for (char letter : *name) {
            letterSum += (toupper(letter) - 65 + 1); // ASCII consonant's start at 65. +1 since A = 0
        }
        
        return letterSum * lineNumber;
    }
    
    void subrun()
    {
        ifstream fileStream = readFile("p022_names.txt");
        
        if (fileStream) {
            
            set<string> *names = new set<string>(); // sort alphabetically
            
            string line;
            while (getline(fileStream, line, '\n')) { // iterate over each line
                names->insert(line);
            }
            
            
            uint64_t sumOfNameScores = 0;
            uint64_t lineNumber = 0;
            
            for (string name : *names) {
                sumOfNameScores += nameScore(&name, ++lineNumber);
            }

            names->clear();
            delete names;

            calculatedAnswer << sumOfNameScores;
            
        }
        
        fileStream.clear();
        fileStream.close();
        
    }
    
    void tdd()
    {
        string *t = new string("colin");
        assert(nameScore(t, 938) == 49714);
        delete t;
    }
    
};




