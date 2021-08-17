#include <iostream>

void ante_terminacion() {
  std::cerr << "terminate() invocado\n";
  std::abort();
}
struct error {};
void f() { throw error{}; }

int main() {
  std::set_terminate(ante_terminacion);
  f();
  return 0;
}
