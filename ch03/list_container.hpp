#ifndef __LIST_CONTAINER_H__
#define __LIST_CONTAINER_H__

#include <list>
#include <initializer_list>
#include "container.hpp"

class List_container : public Container {
  std::list<double> ld;
public:
  List_container() {}
  List_container(std::initializer_list<double> li) : ld{li} {}
  ~List_container() {}

  double& operator[](int i);
  int size() const { return ld.size(); }
};

#endif //__LIST_CONTAINER_H__
