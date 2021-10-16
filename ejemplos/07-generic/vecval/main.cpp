#include <iostream>

#include "vecval.hpp"

int main() {
  cont::vecvalues<int> v{1,2,3};
  std::cout << v[0] << "\n";
  return 0;
}
