#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <initializer_list>
#include <algorithm>

template <typename T>
class Vector {
private:
  T* elem;
  int sz;

public:
  Vector(int s);
  Vector(std::initializer_list<T> lst);
  ~Vector() { delete[] elem; }

  Vector(const Vector<T>& a);
  Vector<T>& operator=(const Vector<T>& a);

  Vector(Vector<T>&& a);
  Vector<T>& operator=(Vector<T>&& a);

  T& operator[](int i);
  const T& operator[](int i) const;
  int size() const;
};

#endif //__VECTOR_H__
