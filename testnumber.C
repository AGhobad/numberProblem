
#include "fraction.H"
#include "integer.H"
#include "util.H"
#include <iostream>

#include <iomanip>
#include <locale>
#include <sstream>
#include <cassert> 
#include <stdlib.h>

using namespace std;

string s;

string itoa(int num)
{
  s.clear();
  s = static_cast<ostringstream*>( &(ostringstream() << num) )->str();
  return s;
}


void testIntegers()
{

  string num;
  cout<<" *********************************Testing Integer class"<<endl;  
  int a;
  a = 100;
  cout<<"creating an Integer:i1="<<a<<endl;
   Integer i1(a);
  num = i1.display();
  assert(num.compare(itoa(a))==0);

  a = 100;
  cout<<"creating an Integer:i2="<<a<<endl;
   Integer i2(a);
  num = i2.display();
  assert(num.compare(itoa(a))==0);

  a = 300;
  cout<<"creating an Integer:i3="<<a<<endl;
   Integer i3(a);
  num = i3.display();
  assert(num.compare(itoa(a))==0);

  a = -55;
  cout<<"creating an Integer:i4="<<a<<endl;
   Integer i4(a);
  num = i4.display();
  assert(num.compare(itoa(a))==0);

  a = 0;
  cout<<"creating an Integer:i5="<<a<<endl;
   Integer i5(a);
  num = i5.display();
  assert(num.compare(itoa(a))==0);

  cout<<"testing  i1==i2, should pass"<<endl;
  assert(i1==i2);
  
  cout<<"testing  i1==i3, should fail"<<endl;  
  assert((i1==i3) == false);

  cout<<"testing  i1==100, should pass"<<endl;
  assert(i1==100);
  
  cout<<"testing  i1==120, should fail"<<endl;  
  assert((i1==120) == false);

  a = i1.getMyInt() +  i3.getMyInt();
  cout<<"creating an Integer:i6= i1 + i3:"<<a<<endl;
  Integer i6 = i1 + i3;
  num = i6.display();
  assert(num.compare(itoa(a))==0);

  a = i4.getMyInt() +  i1.getMyInt();
  cout<<"testing i4 += i1:"<<a<<endl;
  i4 += i1;
  num = i4.display();
  assert(num.compare(itoa(a))==0);
  
  int tmp = 4;
  a = i3.getMyInt() +  tmp;
  cout<<"testing i4 = i3 + "<<tmp<<":"<<a<<endl;
  i4 = i3 + 4;
  num = i4.display();
  assert(num.compare(itoa(a))==0);
   
}

int n,d;
string s1;

string afraction()
{
  char sign = '+';
  if ( (n < 0 && d > 0 ) ||
       (n > 0 && d < 0))
    sign = '-';
       
  s1.clear();
  s1 += sign + itoa(abs(n)) + "/" + itoa(abs(d));
  return s1;
}

void testFractions()
{
  string num;
  cout<<" *********************************Testing Fraction"<<endl;

  n=1;d=2;
  cout<<"creating a Fraction f1:"<<afraction()<< endl;
  Fraction f1(n,d);
  num = f1.display();
  assert(num.compare(afraction())==0);

  n=8;d=16;
  cout<<"creating a Fraction f2:"<<afraction()<< endl;
  Fraction f2(n,d);
  num = f2.display();
  assert(num.compare(afraction())==0);

  n=8;d=17;
  cout<<"creating a Fraction f3:"<<afraction()<< endl;
  Fraction f3(n,d);
  num = f3.display();
  assert(num.compare(afraction())==0);


  n=8;d=0;
  cout<<"creating a Fraction with 0 as denominator f4:"<<afraction()<< endl;
  Fraction f4(n,d);  
  num = f4.display();
  d=1;
  assert(num.compare(afraction())==0);


  n=-2;d=3;
  cout<<"creating a Fraction  with negative numerator ( n=-2;d=3) f10:"<<afraction()<< endl;
  Fraction f10(n,d);
  num = f10.display();
  assert(num.compare(afraction())==0);

  n=2;d=-3;
  cout<<"creating a Fraction  with negative denominator ( n=2;d=-3) f11:"<<afraction()<< endl;
  Fraction f11(n,d);
  num = f11.display();
  assert(num.compare(afraction())==0);

  n=-2;d=-3;
  cout<<"creating a Fraction  with negative numerator & denominator ( n=-2;d=-3) f12:"<<afraction()<< endl;
  Fraction f12(n,d);
  num = f12.display();
  assert(num.compare(afraction())==0);

  cout<<"testing  f10==f11, should pass"<<endl;
   assert(f10==f11);
 
   cout<<"testing  f10==f12, should fail"<<endl;
   assert((f10==f12) == false);
  
  cout<<"testing  f1==f2, should pass"<<endl;
  assert(f1==f2);
  
  cout<<"testing  f1==f3, should fail"<<endl;
  assert((f1==f3) == false);

  n=32;
  d=32;
  cout<<"creating a Fraction:f6= f1 + f2:"<<afraction()<< endl;
  Fraction f6 = f1 + f2;
  num = f6.display();
  assert(num.compare(afraction())==0); 
   
  n=33;
  d=34;
  cout<<"testing f1 += f3:"<<afraction()<< endl;
  f1 += f3;
  num = f1.display();
  assert(num.compare(afraction())==0); 
 
}

void testComparisons()
{
  cout<<" *********************************Testing comparisons betweeen Fraction & Integer"<<endl;
  string num;
  n=8;d=2;
  cout<<"creating a Fraction f1:"<<afraction()<< endl;
  Fraction f1(n,d);
  
  int a;
  a = 4;
  cout<<"creating an Integer:i1="<<a<<endl;
  Integer i1(a);
  
  a = 3;
  cout<<"creating an Integer:i2="<<a<<endl;
  Integer i2(a);
  
  cout <<"testing i1==f1: should pass"<<endl;
  assert(i1==f1);


  cout <<"testing f1==i1: should pass"<<endl;
  assert(f1==i1);
 
  cout <<"testing i2==f1: should fail"<<endl;
  assert((i2==f1) == false);
  
  cout <<"testing f1==i2: should fail"<<endl;
  assert((f1==i2) == false);
  
}

void testAdditions()
{
  cout<<" *********************************Testing adding Integer to Fraction"<<endl;
  string num;
  n=8;d=2;
  cout<<"creating a Fraction f1:"<<afraction()<< endl;
  Fraction f1(n,d);
  
  int a;
  a = 4;
  cout<<"creating an Integer:i1="<<a<<endl;
  Integer i1(a);
  
  a = 3;
  cout<<"creating an Integer:i2="<<a<<endl;
  Integer i2(a);

  n=14;
  d=2;
  cout<<"creating a Fraction:f2= f1 + i2:"<<afraction()<< endl;
  Fraction f2= f1 + i2;
  num = f2.display();
  assert(num.compare(afraction())==0); 

  cout<<"re assiging f2= i2 + f1:"<<afraction()<< endl;
  f2= i2 + f1;
  num = f2.display();
  assert(num.compare(afraction())==0); 

  n=14;
  d=2;
  cout<<"re assiging f2= f1 + 3:"<<afraction()<< endl;
  Fraction f3= f1 + 3;
  f3.display();


  n=14;
  d=2;
  cout<<"re assiging f2= 3 + f1:"<<afraction()<< endl;
  f3= 3 + f1;
  f3.display();


  n=14;
  d=2;
  cout<<"re assiging f2= f1 + 3.34:"<<afraction()<< endl;
  f3= f1 + 3.34;
  f3.display();
  

  n=14;
  d=2;
  cout<<"re assiging f2= 3.45 + f1:"<<afraction()<< endl;
  f3= 3.45 + f1;
  f3.display();

}

void testAssignments()
{
  cout<<" *********************************Testing assigning to a Fraction"<<endl;
  
  string num;
  n=8;d=2;
  cout<<"creating a Fraction f1:"<<afraction()<< endl;
  Fraction f1(n,d);
   
  int a;
  a = 4;
  cout<<"creating an Integer:i1="<<a<<endl;
  Integer i1(a);
  
  n=8;
  d=2;
  cout<<"creating a Fraction:f2= f1:"<<afraction()<< endl;
  Fraction f2 = f1;
  num = f2.display();
  assert(num.compare(afraction())==0);  
 
}


int main() 
{
  
  testIntegers();
  testFractions();
  testComparisons();
  testAdditions();  
  testAssignments();
  


 string num;
  cout<<" *********************************Testing Integer class"<<endl;  
  int a;
  a = -1100;
  cout<<"creating an Integer:i1="<<a<<endl;
   Integer i1(a);
  num = i1.display();
  assert(num.compare(itoa(a))==0);   
}

