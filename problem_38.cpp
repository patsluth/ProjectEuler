//
//  problem_38.h
//  Pandigital multiples
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_38 : public problem_base
{

    string desiredAnswer()
    {
        return "932718654";
    }
    
    /**
     *  A number is pandigital if it contains the digits 1 through 9 exactly
     *  ex- 123456789, 987654321, 789645123, etc
     *
     *  @param i
     *
     *  @return bool
     */
    bool isPandigital(uint64_t i)
    {
        set<uint64_t> *temp = new set<uint64_t>();
        
        while (i > 0) {
            temp->insert(i % 10);
            i /= 10;
        }
        
        bool isPandigital = (temp->size() == 9 && sumOfSet(temp) == 45);
        
        temp->clear();
        delete temp;
        
        return isPandigital;
    }
    
    void subrun()
    {
        uint64_t largestPandigital = 0;
        
        for (uint64_t x = 1; x < 10000; x++) {
            
            uint64_t y = x;
            
            for (uint64_t n = 2; n < 10; n++) { // 2 - 9. We already have 1 by setting y to x
                
                y = concatanate(y, x * n);
                
                if (y > 987654321) { // largest possible pandigital number
                    break;
                }
                
                if (isPandigital(y)){
                    if (largestPandigital < y) {
                        largestPandigital = y;
                    } else {
                        break;
                    }
                }
                
            }
            
        }
        
        calculatedAnswer << largestPandigital;
    }

    void tdd()
    {
        assert(isPandigital(123456789) == true);
        assert(isPandigital(987654321) == true);
        assert(isPandigital(192837465) == true);
        assert(isPandigital(564738291) == true);
        assert(isPandigital(827354961) == true);
    }

};
