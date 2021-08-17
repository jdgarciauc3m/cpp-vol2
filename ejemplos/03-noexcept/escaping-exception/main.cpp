#include <iostream>

struct error {};

void f(int x) {
  if (x > 0) { throw error{}; }
}

int main() {
  int x = 0;
  std::cin >> x;
  f(x);
  std::cout << "Finalizando\n";
}
