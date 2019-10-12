#include <iostream>
using namespace std;

class Vector {
public:
  Vector(int s) : sz{s} { // construct a Vector
    if(sz < 0) throw length_error{"Vector::Vector"};
    elem = new double[sz];
  }
  double& operator[](int i) { // element access: subscripting
    if(i < 0 || size() <= i) throw out_of_range{"Vector::operator[]"};
    return elem[i];
  }
  int size() { return sz; }
private:
  double* elem; // pointer to the elements
  int sz; // the number of elements
};

double read_and_sum(int s) {
  Vector v(s);
  for(int i = 0; i != v.size(); ++i)
    cin >> v[i];

  double sum = 0;
  for(int i = 0; i != v.size(); ++i)
    sum += v[i];

  return sum;
}

int main() {
  cout << "How many numbers? ";

  int s;
  cin >> s;

  try {
    double sum = read_and_sum(s);
    cout << "\nSum: " << sum << "\n";
  } catch(length_error) {
    cout << "You must provide a non-negative quantity of numbers.\n";
    return 1;
  } catch(bad_alloc) {
    cout << "Unable to allocate memory for numbers.\n";
    return 2;
  }
}
