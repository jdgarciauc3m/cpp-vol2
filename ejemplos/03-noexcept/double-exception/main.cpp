#include <iostream>

struct error{};

void aux() { throw error{}; }

struct X {
  ~X() { aux(); }
};

void f() {
  X x;
  throw error{};
} // X::~X() -> terminate()

int main() {
  try { f(); }
  catch(...) {}
  std::cout << "Finalizando\n";
}