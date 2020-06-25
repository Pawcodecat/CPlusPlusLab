#include "fraction.h"
#include<iostream>
int NWD(unsigned int a, unsigned int b)
{

    while( a != b )
        if( a < b ) b -= a; else a -= b;
    return a;
}

int NWW(unsigned int a, unsigned int b)
{
    unsigned long long  t, ab;


    ab = a * b;
    while( b )
    {
        t = b;
        b = a % b;
        a = t;
    }
    ab /= a;
    return ab;
}

Fraction::Fraction(int numerator, int denominator)
{
    setNumerator(numerator);
    setDenominator(denominator);
}

void Fraction::setDenominator(int denominator)
{   if(denominator == 0)throw std::invalid_argument("Denominator must not be 0.");
    this->denominator = denominator;
};


Fraction operator+(const Fraction &fractionFirst, const Fraction &fractionSecond)
{
    int numerator, denominator;
    int Nww = NWW(fractionFirst.getDenominator(), fractionSecond.getDenominator());
    denominator = Nww;
    numerator = fractionFirst.getNumerator() * (Nww / fractionFirst.getDenominator()) +
                fractionSecond.getNumerator() * (Nww / fractionSecond.getDenominator());
    int Nwd = NWD(numerator,denominator);
    numerator /= Nwd;
    denominator /= Nwd;
    Fraction result(numerator, denominator);
    return result;
}

Fraction operator*(const Fraction &fractionFirst, const Fraction &fractionSecond)
{
    int numerator, denominator;
    denominator = fractionFirst.getDenominator() * fractionSecond.getDenominator();
    numerator = fractionFirst.getNumerator() * fractionSecond.getNumerator();
    int Nwd = NWD(numerator,denominator);
    numerator /= Nwd;
    denominator /= Nwd;
    Fraction result(numerator, denominator);
    return result;
}

