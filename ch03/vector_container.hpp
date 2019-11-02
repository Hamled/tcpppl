#ifndef __VECTOR_CONTAINER_H__
#define __VECTOR_CONTAINER_H__

#include <initializer_list>

#include "container.hpp"
#include "vector.hpp"

template <typename T>
class Vector_container : public Container {
  Vector<T> v;
public:
  Vector_container(int s) : v(s) {}
  Vector_container(std::initializer_list<T> lst) : v(lst) {}
  ~Vector_container() {}

  T& operator[](int i) { return v[i]; }
  int size() const { return v.size(); }
};

#endif //__VECTOR_CONTAINER_H__
