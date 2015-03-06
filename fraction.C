


#include "fraction.H"
#include <iostream>
#include <stdlib.h>

using namespace std;

extern string itoa(int num);

/*************************************************/
Fraction::Fraction(int n, int d)
  : numerator (n),
    denominator( (d == 0)? 1: d),
    toDisplay(""),
    sign('+')
{
}

/*************************************************/
const Fraction& Fraction::operator+=(const Fraction & other)
{
  setNumerator((getNumerator() * other.getDenominator()) + (getDenominator() * other.getNumerator()));
  setDenominator(getDenominator() * other.getDenominator());
  
  return *this;
}

/*************************************************/
Fraction Fraction::operator+(const Fraction& other) 
{
  Fraction c(*this);
  return c += other;
}
/*************************************************/
bool Fraction::operator==(const Fraction &other)
{    
  return ((numerator * other.getDenominator())  == (denominator * other.getNumerator()) );

}
/*************************************************/
inline int Fraction::getNumerator() const
   {
     return numerator;
   }
/*************************************************/
inline void Fraction::setNumerator(int i) 
   {
     numerator = i;
   }
/*************************************************/
inline int Fraction::getDenominator() const
   {
     return denominator;
   }
/*************************************************/
inline void Fraction::setDenominator (int i) 
   {
     denominator = (i == 0)? 1: i;
   }
/*************************************************/
  
void Fraction::setSign()
{
  sign = '+';
  if ( (numerator > 0 && denominator < 0 ) ||
       (numerator < 0 && denominator > 0 ))
    sign = '-';
}       
       
/*************************************************/
string  Fraction::display() 
{

  
  toDisplay.clear();
  setSign();
  toDisplay += sign + itoa(abs(numerator)) + "/" + itoa(abs(denominator));
  cout<<toDisplay<<endl;
   return toDisplay; 

}
/*************************************************/


