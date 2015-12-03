//
//  main.cpp
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#ifdef RUN_ALL

#include "problem_1.h"
#include "problem_2.h"
#include "problem_3.h"
#include "problem_4.h"
#include "problem_5.h"
#include "problem_6.h"
#include "problem_7.h"
#include "problem_8.h"
#include "problem_9.h"
#include "problem_10.h"
#include "problem_11.h"
#include "problem_12.h"
#include "problem_13.h"
#include "problem_14.h"
#include "problem_15.h"
#include "problem_16.h"
#include "problem_17.h"
#include "problem_18.h"
//#include "problem_19.h"
#include "problem_20.h"
//#include "problem_21.h"
//#include "problem_22.h"
//#include "problem_23.h"
//#include "problem_24.h"
#include "problem_25.h"
//#include "problem_26.h"
#include "problem_27.h"
//#include "problem_28.h"
//#include "problem_29.h"
#include "problem_30.h"
//#include "problem_31.h"
//#include "problem_32.h"
//#include "problem_33.h"
//#include "problem_34.h"
#include "problem_35.h"
//#include "problem_36.h"
//#include "problem_37.h"
//#include "problem_38.h"
#include "problem_39.h"
//#include "problem_40.h"
//#include "problem_41.h"
#include "problem_42.h"
//#include "problem_43.h"
#include "problem_44.h"
#include "problem_45.h"
#include "problem_46.h"
//#include "problem_47.h"
#include "problem_48.h"
//#include "problem_49.h"
//#include "problem_50.h"
//#include "problem_51.h"
#include "problem_52.h"
//#include "problem_53.h"
//#include "problem_54.h"
//#include "problem_55.h"
//#include "problem_56.h"
//#include "problem_57.h"
//#include "problem_58.h"
//#include "problem_59.h"
//#include "problem_60.h"
#include "problem_61.h"
//#include "problem_62.h"
//#include "problem_63.h"
//#include "problem_64.h"
//#include "problem_65.h"
//#include "problem_66.h"
#include "problem_67.h"
//#include "problem_68.h"
//#include "problem_69.h"


#include "problem_74.h"
#include "problem_76.h"
#include "problem_80.h"
#include "problem_81.h"
#include "problem_82.h"

//#include "problem_87.h"
//
//
//#include "problem_92.h"
//
//#include "problem_95.h"
//#include "problem_99.h"

#else

#include "problem_82.h"
#include "problem_61.h"
#include "problem_46.h"

#endif







int main(int, char**)
{
    cout << "Project Euler - Pat Sluth" << endl << "Starting..." << endl << endl;
    
    problem_46().run();
   // problem_61().run();
   // problem_82().run();
    
    #ifdef BUILD_ALL
    
    
    
    problem_1().run();
    problem_2().run();
    problem_3().run();
    problem_4().run();
    problem_5().run();
    problem_6().run();
    problem_7().run();
    problem_8().run();
    problem_9().run();
    problem_10().run();
    problem_11().run();
    problem_12().run();
    problem_13().run();
    problem_14().run();
    problem_15().run();
    problem_16().run();
    problem_17().run();
    problem_18().run();
//    problem_19().run();
    problem_20().run();
//    problem_21().run();
//    problem_22().run();
//    problem_23().run();
//    problem_24().run();
//    problem_25().run();
//    problem_26().run();
    problem_27().run();
//    problem_28().run();
//    problem_29().run();
    problem_30().run();
//    problem_31().run();
//    problem_32().run();
//    problem_33().run();
//    problem_34().run();
    problem_35().run();
//    problem_36().run();
//    problem_37().run();
//    problem_38().run();
//    problem_39().run();
//    problem_40().run();
//    problem_41().run();
    problem_42().run();
//    problem_43().run();
    problem_44().run();
    problem_45().run();
    problem_46().run();
//    problem_47().run();
    problem_48().run();
//    problem_49().run();
//    problem_50().run();
//    problem_51().run();
    problem_52().run();
//    problem_53().run();
//    problem_54().run();
//    problem_55().run();
//    problem_56().run();
//    problem_57().run();
//    problem_58().run();
//    problem_59().run();
//    problem_60().run();
    problem_61().run();
//    problem_62().run();
//    problem_63().run();
//    problem_64().run();
//    problem_65().run();
//    problem_66().run();
    problem_67().run();
//    problem_68().run();
//    problem_69().run();
    
    problem_74().run();
    
    problem_80().run();
    problem_81().run();
    problem_82().run();
    problem_87().run();
    
    problem_92().run();
    problem_95().run();
    
    problem_99().run();
    
#endif

    return EXIT_SUCCESS;
}
