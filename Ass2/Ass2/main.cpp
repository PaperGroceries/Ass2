//
//  main.cpp
//  Ass2
//
//  Created by Aim Kim on 2022-07-13.
//

#include <iostream>
#include <fstream>
#include <string>

class RationalNumber
{
    int a;
    int b;
public:
    RationalNumber();
    RationalNumber(int divident);
    RationalNumber(int divident, int divisor);
    int add();
    void less();
    double mul();
    double sub();
    double div();
    void input();
    void output();
    //considering turning into string since the division is not carried out
    
};
RationalNumber::RationalNumber()
{
    a = 0;
    b = 1;
};
RationalNumber::RationalNumber(int divident)
{
    a = divident;
    b = 1;
};
RationalNumber::RationalNumber(int divident, int divisor)
{
    a = divident;
    b = divisor;
    if(b < 0)
    {
        b *= -1;
        a *= -1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
    
}
