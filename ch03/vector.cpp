#include <algorithm>

#include "vector.hpp"

Vector::Vector(int s) : elem{new double[s]}, sz{s} {
  for (int i = 0; i != s; ++i)
    elem[i] = 0;
}

Vector::Vector(std::initializer_list<double> lst)
  : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem);
}

Vector::Vector(const Vector& a)
  : elem{new double[a.sz]}, sz{a.sz} {
    std::copy(a.elem, a.elem + a.sz, elem);
}

Vector& Vector::operator=(const Vector &a) {
  delete[] elem;

  sz = a.sz;
  elem = new double[sz];
  std::copy(a.elem, a.elem + sz, elem);

  return *this;
}

double& Vector::operator[](int i) {
  return elem[i];
}

const double& Vector::operator[](int i) const {
  return elem[i];
}

int Vector::size() const {
  return sz;
}
