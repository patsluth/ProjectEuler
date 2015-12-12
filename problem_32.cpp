//
//  problem_32.h
//  Pandigital products
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_32 : public problem_base
{

    string desiredAnswer()
    {
        return "45228";
    }
    
    void subrun()
    {
        set<uint64_t> *products = new set<uint64_t>();;
        
        for (uint64_t x = 1; x < 10000; x++) {
            for (uint64_t y = 1; y < 10000; y++) {
                
                uint64_t concat = concatanate(x, y);
                uint64_t product = x * y;
                concat = concatanate(concat, product);
                
                if (concat > 987654321) { // largest possible 9 digit pandigital number
                    break;
                }
                
                if (isPandigital(concat, 9) == true){
                    
                    products->insert(product);
                    
                }
                
            }
            
        }

        calculatedAnswer << sumOfSet(products);
        
        products->clear();
        delete products;
    }
    
    void tdd()
    {
        assert(isPandigital(123456789, 9) == true);
        assert(isPandigital(12345678, 8) == true);
        assert(isPandigital(1234567, 7) == true);
        assert(isPandigital(123456, 6) == true);
        assert(isPandigital(12345, 5) == true);
        assert(isPandigital(1234, 4) == true);
        assert(isPandigital(123, 3) == true);
        assert(isPandigital(12, 2) == true);
        assert(isPandigital(1, 1) == true);
    }

};
