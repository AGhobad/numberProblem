
#ifndef DA_1_UTIL_H
#define DA_1_UTIL_H


#include <string>

 using namespace std;


template<class T1, class T2>
  bool operator==(const NumberBase<T1> &first,const NumberBase<T2> &second);


Fraction operator+(const Fraction &first,const Integer  &second);
Fraction operator+(const Integer  &first,const Fraction &second);

#endif


