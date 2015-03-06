
#include <iostream>
#include "fraction.H"
#include "integer.H"

#include "util.H"

using namespace std;

/************************************************************/
template<class T1, class T2>
bool operator==(const NumberBase<T1> &first,const NumberBase<T2> &second)
{   
  Integer *i =(Integer*) dynamic_cast<const Integer*>(&first);
  Fraction *f =(Fraction*) dynamic_cast<const Fraction*>(&second);
  if (i != NULL && f != NULL)
    {
      Fraction f1 (i->getMyInt(),1);
      return (*f == f1);
    }
  
  i =(Integer*) dynamic_cast<const Integer*>(&second);
  f =(Fraction*) dynamic_cast<const Fraction*>(&first);
  if (i != NULL && f != NULL)
    {
      Fraction f1 (i->getMyInt(),1);
      return (*f == f1);
    }
  return false;

}
/************************************************************/
// F = F + I
Fraction operator+(const Fraction &first,const Integer &second)
{  
  Fraction f1 (second.getMyInt(),1);
  return (f1 + first);
}
/************************************************************/

// F = I + F

Fraction operator+(const Integer &first,const Fraction &second)
{
  Fraction f1 (first.getMyInt(),1);
  return (f1 + second);
}

/************************************************************/

template
bool operator==<Integer, Fraction>(NumberBase<Integer> const&, NumberBase<Fraction> const&);

template
bool operator==<Fraction, Integer>(NumberBase<Fraction> const&, NumberBase<Integer> const&);


/*
template
Fraction operator+<Fraction, Integer>(NumberBase<Fraction> const&, NumberBase<Integer> const&);

template
Fraction operator+<Integer, Fraction>(NumberBase<Integer> const&, NumberBase<Fraction> const&);
*/
