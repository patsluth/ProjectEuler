//
//  problem_99.h
//  Largest exponential
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <math.h>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_99 : public problem_base
{
    
    string desiredAnswer()
    {
        return "709";
    }
    
    typedef vector<uint64_t> baseExponent;
    
    /**
     *  Calculates and returns the larger exponent very fast
     *  using logarithm change of base formula and comparing the exponents
     *
     *  @param be1
     *  @param be2
     *
     *  @return baseExponent
     */
    baseExponent largerExponent(baseExponent be1, baseExponent be2)
    {
        //the value that be2's base must be raised to (exponent) to have the same base as be1
        float be2_changeOfBaseExponent = log(be1.front()) / log(be2.front());
        be2_changeOfBaseExponent *= be1.back();
        
        if (be2.back() > be2_changeOfBaseExponent){ //if be2's original exponent is larger than the change of base, then be2 is larger
            return be2;
        } else {
            return be1;
        }
    }
    
    void subrun()
    {
        string file = "p099_base_exp.txt";
        ifstream fileStream(file);
        
        
        if (fileStream){
            
            vector<baseExponent> exponents;
            
            string line;
            uint64_t lineNumber = 0;
            
            while (getline(fileStream, line, '\n')) { //iterate file line by line
                
                lineNumber++;
                
                istringstream buf(line);
                istream_iterator<uint64_t> beg(buf), end;
                
                baseExponent be(beg, end);
                be.insert(be.begin() + 1, lineNumber); //line number stored in center index
                exponents.push_back(be);
                
            }
            
            while (exponents.size() > 1){
                
                baseExponent be1 = exponents.back();
                exponents.pop_back();
                baseExponent be2 = exponents.back();
                exponents.pop_back();
                
                exponents.push_back(largerExponent(be1, be2));
            }
            
            calculatedAnswer << exponents.front()[1]; //line number stored in center index
            
        } else {
            
            fprintf(stderr, "Error reading %s\n", file.c_str());
            
        }
    }
    
};




