//
//  problem_39.h
//  Integer right triangles
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_39 : public problem_base
{
    
    string desiredAnswer()
    {
        return "840";
    }
    
    void subrun()
    {
        pair<uint64_t, uint64_t> maxSolutions = {0, 0}; //first = # of solutions, second = p
        
        for (uint64_t p = 1; p <= 1000; p++) { //try all p
            
            uint64_t numberOfSolutions = 0;
            
            for (uint64_t a = 1; a <= (p / 2); a++) {
                for (uint64_t b = a; b <= (p / 2); b++) {
                    
                    double c = sqrt((a * a) + (b * b));
                    
                    if (fmod(c, (uint64_t)c) == 0.0) { //make sure c is a whole number
                        
                        if ((uint64_t)(c) + a + b == p) { //make sure perimeter is correct
                            
                            double angle1 = atan((double)a / (double)b);
                            double angle2 = atan((double)b / (double)a);
                            
                            if ((angle1 + angle2) == M_PI_2) { //right triangle
                                numberOfSolutions++;
                            }
                            
                        }
                        
                    }
                    
                }
            }
            
            if (numberOfSolutions > maxSolutions.first) {
                maxSolutions.first = numberOfSolutions;
                maxSolutions.second = p;
            }
            
        }
        
        calculatedAnswer << maxSolutions.second;
    }
    
};




