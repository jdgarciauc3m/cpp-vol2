#include <iostream>

#include "listnum.hpp"

int main() {
  listnum l;
  l.agrega_final(2.0);
  l.agrega_final(3.0);
  l.agrega_final(4.0);
  listnum m{l};
  std::cout << "l = (" << l << ")\n";
  std::cout << "m = (" << m << ")\n";

  for (auto it = l.inicio(); it != l.fin(); ++it) {
    std::cout << "->" << *it << "\n";
  }

  return 0;
}
