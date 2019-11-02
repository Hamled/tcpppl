#include "vector.hpp"

double& Vector::operator[](int i) {
  return elem[i];
}

int Vector::size() const {
  return sz;
}
