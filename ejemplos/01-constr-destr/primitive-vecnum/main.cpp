#include <iostream>

#include "vecnum.hpp"

int main() {
  vecnum v{5};
  v[2] = 3.0;
  for (int i=0; i<v.tamanyo(); ++i) {
    std::cout << "v[" << i << "] = " << v[i] << '\n';
  }

  return 0;
}
