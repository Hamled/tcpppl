#include <iostream>

#include "container.hpp"
#include "vector_container.hpp"
#include "list_container.hpp"

void use(Container& c) {
  const int sz = c.size();

  for(int i = 0; i != sz; ++i) {
    std::cout << c[i] << '\n';
  }
}

void g() {
  Vector_container<double> vc{10,9,8,7,6,5,4,3,2,1,0};

  use(vc);
}

void h() {
  List_container lc = {1,2,3,4,5,6,7,8,9};

  use(lc);
}

int main() {
  g();
  std::cout << "---" << '\n';
  h();
}
