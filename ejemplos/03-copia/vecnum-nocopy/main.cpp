#include <iostream>

#include "vecnum.hpp"

int main() {
  vecnum v1(5);
  v1[2] = 5.0;
  v1[4] = 3.5;

  vecnum v2 {v1};
  std::cout << "v1: (" << v1 << ")\n";
  std::cout << "v2: (" << v2 << ")\n";

  return 0;
}
