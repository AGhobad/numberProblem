
#ifndef DA_1_NUMBERBASE_H
#define DA_1_NUMBERBASE_H


#include <string>

 using namespace std;

template<class T>
class NumberBase
{
 public:

  virtual bool operator==(const T &other) = 0;
  virtual T operator+(const T& other) =0;

  virtual string   display() = 0;
  
};

#endif


