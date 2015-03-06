
#ifndef DA_1_FRACTION_H
#define DA_1_FRACTION_H

/**
 * Fraction class
 * This simple class represents a fraction, which is represented by  its numerator and denominator 
 * A if denominator is 0, it is changed to 1.
 * the following operatoions are supported:
 * Note: Fx represents "Fraction  Fx;"
 * Fraction F3 = F1 + F2;
 * F3 += F1;
 * F1 == F2
 * F1 = I1
 * F1 == I1
 * I1 == F1
 * F2 = F1 + I1
 * F2 = I2 + F1
 * F1 = F2
 * F1 = F1 + i1 (where i1 is any primitive convertibale to an int)
 * F1 = i1 + F1 (where i1 is any primitive convertibale to an int)
 *
 * the following operations are not supported:
 * F1++
 * ++F1
 * F1 == 0.4  (or any other kind of pro`mitive)
 * F1 = I1
 * 
 */

#include "numberbase.H"

class Fraction: public NumberBase<Fraction>
{
 public:

  Fraction(int n, int d);  //if d is 0, it is changed to 1.
  
  Fraction operator+(const Fraction& other) ;
  const Fraction& operator+=(const Fraction & other);
  bool operator==(const Fraction &b);
  
   string display() ;
 
   int getNumerator() const;
   void setNumerator(int i) ;  
   
   int getDenominator() const;
   void setDenominator (int i);

 private:
   int numerator ;
   int denominator ;
   string toDisplay;
   char sign;
   
   void setSign();
};

#endif


