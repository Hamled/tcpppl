#ifndef __CONTAINER_H__
#define __CONTAINER_H__

class Container {
public:
  virtual double& operator[](int) = 0;
  virtual int size() const = 0;
  virtual ~Container() {};
};

#endif //__CONTAINER_H__
