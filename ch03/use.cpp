#include <iostream>

#include "container.hpp"
#include "vector_container.hpp"

void use(Container& c) {
  const int sz = c.size();

  for(int i = 0; i != sz; ++i) {
    std::cout << c[i] << '\n';
  }
}

void g() {
  Vector_container vc{10,9,8,7,6,5,4,3,2,1,0};

  use(vc);
}

int main() {
  g();
}
