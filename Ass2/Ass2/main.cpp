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
    double add(RationalNumber &);
    bool less(RationalNumber &);
    double mul(RationalNumber &);
    double sub(RationalNumber &);
    double div(RationalNumber &);//im a dog woof woof
    int input(fstream &);
    void get();
    void set(int new_num, int new_den);
    //thinking of overloading the functions
    //meybe no parameter ones will input the private rational number
    int output(fstream &);//file out put and screen output?
    void output(iostream & cout);
    //ifstream.open("Rationals.txt");
    //i think i am going to put it into functions
    
    //considering turning into string since the division is not carried out
    
    //write getnum
    //get denom
    void get_num();
    void get_den();
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
    ifstream >> numerator;
    ifstream.ignore();
    ifstream >> denominator;
    ifstream.ignore();
    return 0;
};
int RationalNumber::output(fstream & ofstream)
{
    ofstream << numerator << "/" << denominator << endl;
    return 0;
};
double RationalNumber::add(RationalNumber & b)
{
    //should it be a string?
    //i am not sure how to return it as int
    // (a * d + b * c)/(b * d)
    //a/b +c/d
    return (numerator * b.denominator + denominator * b.numerator)/(denominator * b.denominator * 1.0);
};
double RationalNumber::sub(RationalNumber & b)
{
    return (numerator * b.denominator - denominator * b.numerator)/(denominator * b.denominator * 1.0);
};
double RationalNumber::mul(RationalNumber & b)
{
    //a/b * c/d  (a * c)/(b * d)
    return (numerator * b.numerator)/(denominator * b.denominator * 1.0);
};
double RationalNumber::div(RationalNumber &b)
{
    //(a * d)/(c * b)
    return (numerator * b.denominator)/(b.numerator * denominator * 1.0);
};
bool RationalNumber::less(RationalNumber &b)
{
    // a/b < c/d   (a * d) < (c *b)
    return ((numerator * b.denominator) < (b.numerator * denominator));
};
void RationalNumber::get()
{
    cout << numerator << "/" << denominator << endl;
};
void RationalNumber::set(int n_num,int n_den)
{
    numerator = n_num;
    denominator = n_den;
};
void RationalNumber::get_num()
{
    cout << numerator;
};
void RationalNumber::get_den()
{
    cout << denominator;
}
//void RationalNumber::output(iostream & kcout)
//{
//    kcout << numerator << "/" << denominator;
//};



int main(int argc, const char * argv[]) {
    //decide whether you are going to have separate input and output files
    //add memeber fucntion bodies or intializations
    //think how u plan to output code in txt
    //think of how u plan input code to main from private or txt
    //test cases
    
    //finish output and input with text files and test them
    
    // insert code here...
    bool yes = false;
    int num;
    int den;
    std::cout << "Hello, World!\n";
    RationalNumber a(1,6);
    RationalNumber b(1,3);
    RationalNumber c(1,20);
    
    cout <<  "x is " ;
    a.get();
    cout <<  "y is " ;
    b.get();
    cout << "x is less than y" << endl;
    if (a.less(b))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
   
    cout << "x + y = " << a.add(b)<<endl; // 0.5
    cout << "x * y = " << a.mul(b)<<endl; // 0.0555556
    cout << "y / x = " << b.div(a)<<endl;//2
    cout << "x - y = " << a.sub(b)<<endl;//-0.166667
    fstream ifstream, ofstream;
    ofstream.open("Rationals.txt",fstream::app);
    ifstream.open("Rationals.txt");
//    a.output(ofstream);
//    b.output(ofstream);
    c.input(ifstream); // 1/6
    c.get(); // 1/6
    cout << "was just read from Rationals.txt" << endl;
    //I have get num and den, ask if i should demonstrate them
    do
    {
        cout << "Pls enter numerator" << endl;
        cin >> num;
        cout << "Pls enter  denominator" << endl;
        cin >> den;
        cout << "would you like to re-input another rational number? (1 yes || 0 no)" << endl;
        cin >> yes;

    }while (yes);
    
    RationalNumber d(num,den);
    d.output(ofstream);
    
    cout << "the number is recorded in txt file" << endl;
    //does he want us to make objects from  ui
    //nuh i think he meant this area as keayboard
    //but if he want that we can always make cin into integers and put those integers into object as arguments
    
    
    
    return 0;
    
}
