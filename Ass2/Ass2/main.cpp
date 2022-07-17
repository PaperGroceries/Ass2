//
//  main.cpp
//  Ass2
//
//  Created by Aim Kim on 2022-07-13.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class RationalNumber
{
    int numerator;
    int denominator;
    int r_num;
    int r_den;
public:
    RationalNumber();
    RationalNumber(int divident);
    RationalNumber(int divident, int divisor);
    fstream ifstream, ofstream;
    double add(RationalNumber & b);
    int less();
    int mul();
    int sub();
    int div();
    int input(fstream & ifstream);
    //thinking of overloading the functions
    //meybe no parameter ones will input the private rational number
    int output(fstream & ofstream);//file out put and screen output?
    
    //ifstream.open("Rationals.txt");
    //i think i am going to put it into functions
    
    //considering turning into string since the division is not carried out
    
};
RationalNumber::RationalNumber()
{
    numerator = 0;
    denominator = 1;
};
RationalNumber::RationalNumber(int divident)
{
    numerator = divident;
    denominator = 1;
};
RationalNumber::RationalNumber(int divident, int divisor)
{
    numerator = divident;
    denominator = divisor;
    if(denominator < 0)
    {
        denominator *= -1;
        numerator *= -1;
    }
    if(denominator == 0)
    {
        cout << "we have reassigned denominator to 1, since it cannot be 0";
        denominator = 1;
    }
}
int RationalNumber::input(fstream & ifstream)
{
    ifstream.open("Rationals.txt");
    ifstream >> numerator ;
    ifstream.ignore();
    ifstream >> denominator;
    ifstream.ignore();
    return 0;
};
int RationalNumber::output(fstream & ofstream)
{
    ifstream.open("Rationals.txt");
    ofstream << numerator << "/" << denominator << endl;
    return 0;
};
double RationalNumber::add(RationalNumber & b)
{
    //should it be a string?
    //i am not sure how to return it as int
    // (a * d + b * c)/(b * d)
    //a/b +c/d
    double f_n = (numerator * b.denominator + denominator * b.numerator)/(denominator * b.denominator * 1.0);
    return f_n;

};
//int RationalNumber::sub()
//{
//
//};
//int RationalNumber::mul()
//{
//
//};
//int RationalNumber::div()
//{
//
//};


int main(int argc, const char * argv[]) {
    //decide whether you are going to have separate input and output files
    //add memeber fucntion bodies or intializations
    //think how u plan to output code in txt
    //think of how u plan input code to main from private or txt
    //test cases
    
    // insert code here...
    std::cout << "Hello, World!\n";
    RationalNumber a(1,2);
    RationalNumber b(1,3);
    cout << a.add(b);
    
    
    
    return 0;
    
}
