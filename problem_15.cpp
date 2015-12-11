//
//  problem_15.h
//  Lattice paths
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;
using namespace boost::multiprecision;





class problem_15 : public problem_base
{

    string desiredAnswer()
    {
        return "137846528820";
    }

    cpp_int nCr(cpp_int n, cpp_int r)
    {
        cpp_int nFact = cppint_factorial(n);
        cpp_int rFact = cppint_factorial(r);
        cpp_int nrFact = cppint_factorial(n - r);

        return nFact / (rFact * nrFact);
    }

    void subrun()
    {
        cpp_int n = 20;

//        for (uint64_t x = 0; x < 3; x++) {
//            for (uint64_t y = 0; y < 3; y++) {
//
//                if ((x == 0 && y == 0) || (x == 3 && y == 3)) {
//
//                } else {
//                    paths++;
//                }
//
//            }
//        }
//
        cout << nCr(n * 2, n);
        calculatedAnswer << nCr(n * 2, n);
    }

};
