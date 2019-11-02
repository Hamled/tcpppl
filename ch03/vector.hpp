#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <initializer_list>
#include <algorithm>

class Vector {
private:
  double* elem;
  int sz;

public:
  Vector(int s);
  Vector(std::initializer_list<double> lst);
  ~Vector() { delete[] elem; }

  Vector(const Vector& a);
  Vector& operator=(const Vector& a);

  double& operator[](int i);
  const double& operator[](int i) const;
  int size() const;
};

#endif //__VECTOR_H__
