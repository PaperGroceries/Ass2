//
//  main.cpp
//  Ass2
//
//  Created by Aim Kim on 2022-07-13.
//s

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
    
    bool eqv(RationalNumber &);
    //ifstream.open("Rationals.txt");
    //i think i am going to put it into functions
    
    //considering turning into string since the division is not carried out
    
    //write getnum
    //get denom
    int get_num();
    int get_den();
    
    int get_rnum();
    int get_rden();
    
    int gcd(int a, int b);
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
        cout <<"the minus sign was in denomenator,we have put the minus sign into numerator"<<endl;
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
    int this_gcd;
    r_num =(numerator * b.denominator + denominator * b.numerator);
    r_den =(denominator * b.denominator);
    this_gcd = gcd(r_num, r_den);
    r_num /= this_gcd;
    r_den /= this_gcd;
    return (numerator * b.denominator + denominator * b.numerator)/(denominator * b.denominator * 1.0);
};
double RationalNumber::sub(RationalNumber & b)
{
    int this_gcd;
    r_num =(numerator * b.denominator - denominator * b.numerator);
    r_den =(denominator * b.denominator);
    this_gcd = gcd(r_num, r_den);
    r_num /= this_gcd;
    r_den /= this_gcd;
    return (numerator * b.denominator - denominator * b.numerator)/(denominator * b.denominator * 1.0);
};
double RationalNumber::mul(RationalNumber & b)
{
    //a/b * c/d  (a * c)/(b * d)
    int this_gcd;
    r_num = numerator * b.numerator;
    r_den = denominator * b.denominator;
    this_gcd = gcd(r_num, r_den);
    r_num /= this_gcd;
    r_den /= this_gcd;
    return (numerator * b.numerator)/(denominator * b.denominator * 1.0);
};
double RationalNumber::div(RationalNumber &b)
{
    //(a * d)/(c * b)
    int this_gcd;
    r_num = numerator * b.denominator;
    r_den = b.numerator * denominator;
    this_gcd = gcd(r_num, r_den);
    r_num /= this_gcd;
    r_den /= this_gcd;
    return (numerator * b.denominator)/(b.numerator * denominator * 1.0);
};
bool RationalNumber::less(RationalNumber &b)
{
    // a/b < c/d   (a * d) < (c *b)
    return ((numerator * b.denominator) < (b.numerator * denominator));
};
void RationalNumber::get()
{
    cout << numerator << "/" << denominator;
};
void RationalNumber::set(int n_num,int n_den)
{
    numerator = n_num;
    denominator = n_den;
};
int RationalNumber::get_num()
{
    return numerator;
};
int RationalNumber::get_den()
{
    return denominator;
}
int RationalNumber::get_rnum()
{
    return r_num;
}
int RationalNumber::get_rden()
{
    return r_den;
}
int RationalNumber::gcd(int a, int b)
{
    if (b == 0)
       return a;
    else
       return gcd(b, a % b);
}
bool RationalNumber::eqv(RationalNumber & b)
{
    return (numerator * b.denominator) == (b.numerator * denominator);
   // (a/b) == (c/d) means (a * d) == (c * b)
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
    int x = 0;
    std::cout << "Hello, World!\n";
    RationalNumber a(3,2);
    RationalNumber b(-1,2);
    RationalNumber c(1,2);
    RationalNumber d(1,-2);
    RationalNumber e(2,4);
//    cout <<  "x is " ;
//    a.get();
//    cout <<  "y is " ;
//    b.get();
    a.add(b);
    cout << a.get_num() << "/" << a.get_den() << " + " << b.get_num() << "/"<< b.get_den()<< " = " << a.get_rnum() <<
            "/"<< a.get_rden()<<endl; //
    a.sub(c);
    cout << a.get_num() << "/" << a.get_den() << " - " << c.get_num() << "/"<< c.get_den()<< " = " << a.get_rnum() <<
    "/"<< a.get_rden()<<endl; //
    a.mul(c);
    cout << a.get_num() << "/" << a.get_den() << " * " << c.get_num() << "/"<< c.get_den()<< " = " << a.get_rnum() <<
    "/"<< a.get_rden()<<endl; //
    a.div(c);
    cout << a.get_num() << "/" << a.get_den() << " / " << c.get_num() << "/"<< c.get_den()<< " = "  << a.get_rnum() <<
    "/"<< a.get_rden()<<endl; //
    
    
    a.get();
    cout << " < ";
    c.get();
    cout << " is ";
    if (a.less(c))
    {
        cout <<  "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    c.get();
    cout << " < ";
    a.get();
    cout << " is ";
    if (c.less(a))
    {
        cout <<  "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    a.get();
    cout << " == ";
    c.get();
    cout << " is ";
    if (a.eqv(c))
    {
        cout <<  "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    e.get();
    cout << " == ";
    c.get();
    cout << " is ";
    if (e.eqv(c))
    {
        cout <<  "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    
    fstream ifstream, ofstream;
    ofstream.open("Rationals.txt",fstream::app);
    ifstream.open("Rationals.txt");
//    a.output(ofstream);
//    b.output(ofstream);
    c.input(ifstream); // 1/6
    c.get(); // 1/6
    cout << " was just read from Rationals.txt" << endl;
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
    cout<< "would you like to save the rational number to Rationals.txt ? " << endl;
    cin >> x;
    if(x)
    {
        RationalNumber d(num,den);
        d.output(ofstream);
        cout << "the number is recorded in txt file" << endl;
    }
   
    
    
    //does he want us to make objects from  ui
    //nuh i think he meant this area as keayboard
    //but if he want that we can always make cin into integers and put those integers into object as arguments
    
    
    
    return 0;
    
}
