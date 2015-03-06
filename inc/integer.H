
#ifndef DA_1_INTEGER_H
#define DA_1_INTEGER_H



/**
 * Integer class
 * This simple class represents an integer
 * the following operatoions are supported:
 * Note: Ix represents "Interger  Ix;"
 * Integer I3 = I1 + I2;
 * I3 += I1;
 * I3 = I1 + 4;
 * I1==I2
 * I1==4

 * the following operations are not supported:
 * I1++
 * ++I1
 * I3 = 4 + I1
 * 4==I1
 *
 */
#include "numberbase.H"

class Integer: public NumberBase<Integer>

{
 public:

  Integer(int i);

  Integer operator+(const Integer& other) ;
  const Integer& operator+=(const Integer & other)
    {
      return *this;
    }
  bool operator==(const Integer &b); 
  string display() ;

  int getMyInt() const;
  void setMyInt(int i);
  
 private:
  int myInt;
  string toDisplay;
};

#endif


