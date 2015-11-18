//
//  main.cpp
//  problem_17
//  Power digit sum
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <string>

using namespace std;




string stringFromInt_ten(uint16_t i)
{
    switch (i) {
        case 9:
            return "ninety";
            break;
            
        case 8:
            return "eighty";
            break;
            
        case 7:
            return "seventy";
            break;
            
        case 6:
            return "sixty";
            break;
            
        case 5:
            return "fifty";
            break;
            
        case 4:
            return "forty";
            break;
            
        case 3:
            return "thirty";
            break;
            
        case 2:
            return "twenty";
            break;
            
        case 1:
            return "ten";
            break;
            
        default:
            return "";
            break;
    }
}

string stringFromInt_one(uint16_t i)
{
    switch (i) {
        case 9:
            return "nine";
            break;
            
        case 8:
            return "eight";
            break;
            
        case 7:
            return "seven";
            break;
            
        case 6:
            return "six";
            break;
            
        case 5:
            return "five";
            break;
            
        case 4:
            return "four";
            break;
            
        case 3:
            return "three";
            break;
            
        case 2:
            return "two";
            break;
            
        case 1:
            return "one";
            break;
            
        default:
            return "";
            break;
    }
}

string stringFromInt(uint16_t i)
{
    if (i <= 1000){ //to large
        
        if (i >= 100){
            
            string returnVal = "";
            
            if (i >= 1000){
                returnVal += stringFromInt_ten(i / 1000) + "thousand";
            }
            if (i / 100 % 10 != 0){
                returnVal += stringFromInt_one(i / 100 % 10) + "hundred";
            }
            if (i % 100 != 0){
                returnVal += "and" + stringFromInt_ten(i % 100);
            }
            
            return returnVal;
            
        } else {
            
            if (i < 10){
                return stringFromInt_one(i);
            } else if (i < 20){
                return stringFromInt_ten(i);
            } else {
                return stringFromInt_ten(i) + stringFromInt_one(i % 10);
            }
        }
        
    }
    
    return "invalid";
}

int main(int argc, const char * argv[])
{
    //for (uint x = 0; x < 5; x++){
        //cout << stringFromInt(x) << endl;
    //}
    
    cout << stringFromInt(999) << endl;
    
    //cout << stringFromInt(1500) << endl;
    
    //cout << stringFromInt(503) << endl;
    
    return 0;
}




