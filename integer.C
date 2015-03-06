
#include "integer.H"
#include <iostream>

extern string itoa(int num);

using namespace std;

/*************************************************/
Integer::Integer(int i)
  :myInt(i),
   toDisplay("")
{
}

/*************************************************/
const Integer& Integer::operator+=(const Integer & other)
{
  myInt+= other.getMyInt();
  
  return *this;
}

/*************************************************/

Integer Integer::operator+(const Integer& other) 
{  
  Integer c(*this);
  return c += other;
}
/*************************************************/
bool Integer::operator==(const Integer &other)
{  
  return (myInt == other.getMyInt());
}
/*************************************************/
inline int Integer::getMyInt() const
{
  return myInt;
}
/*************************************************/
inline void Integer::setMyInt(int i)
{
  myInt = i;
}
/*************************************************/

string  Integer::display() 
{

  toDisplay.clear();
  toDisplay += itoa(myInt);     
  cout<<toDisplay<<endl;
   return toDisplay; 
}
/*************************************************/
