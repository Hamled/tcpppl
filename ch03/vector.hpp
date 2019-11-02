#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <initializer_list>
#include <algorithm>

class Vector {
private:
  double* elem;
  int sz;

public:
  Vector(int s) : elem{new double[s]}, sz{s} {
    for(int i = 0; i != s; ++i) elem[i] = 0;
  }

  Vector(std::initializer_list<double> lst)
      : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem);
  }

  ~Vector() { delete[] elem; }

  double& operator[](int i);
  int size() const;
};

#endif //__VECTOR_H__
