#include <stdexcept>
#include "list_container.hpp"

double& List_container::operator[](int i) {
  for(auto& x : ld) {
    if(i == 0) return x;
    --i;
  }

  throw std::out_of_range("List container");
}
