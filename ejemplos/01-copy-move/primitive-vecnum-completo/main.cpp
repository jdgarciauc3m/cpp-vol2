#include <iostream>

#include "vecnum.hpp"

void print(const std::string & name, const vecnum & v) {
  for (int i=0; i<v.tamanyo(); ++i) {
    std::cout << name << "[" << i << "] = " << v[i] << '\n';
  }
  std::cout << '\n';
}

int main() {
  vecnum v{3};
  v[0] = 3.0;
  print("v", v);

  vecnum w(2);
  w[1] = 3.0;
  print("w", w);

  vecnum t{1,2,3};
  print("t", t);

  return 0;
}
