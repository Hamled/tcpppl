#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <algorithm>
#include <initializer_list>
#include <new>
#include <stdexcept>

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

template <typename T>
Vector<T>::Vector(int s) {
  if(s < 0)
    throw std::bad_array_new_length {};

  sz = s;
  elem = new T[sz];

  for (int i = 0; i != s; ++i)
    elem[i] = 0;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
  : elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& a)
  : elem{new T[a.sz]}, sz{a.sz} {
    std::copy(a.elem, a.elem + a.sz, elem);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a) {
  delete[] elem;

  sz = a.sz;
  elem = new T[sz];
  std::copy(a.elem, a.elem + sz, elem);

  return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& a)
  : elem{a.elem}, sz{a.sz} {
    a.elem = nullptr;
    a.sz = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& a) {
  elem = a.elem;
  sz = a.sz;

  a.elem = nullptr;
  a.sz = 0;

  return *this;
}

template <typename T>
T& Vector<T>::operator[](int i) {
  if (i < 0 || size() <= i)
    throw std::out_of_range{"Vector::operator[]"};
  return elem[i];
}

template <typename T>
const T& Vector<T>::operator[](int i) const {
  if(i < 0 || size() <= i)
    throw std::out_of_range {"Vector::operator[]"};
  return elem[i];
}

template <typename T>
int Vector<T>::size() const {
  return sz;
}

#endif //__VECTOR_H__
