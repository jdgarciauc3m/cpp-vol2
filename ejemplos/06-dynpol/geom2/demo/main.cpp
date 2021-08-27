#include <iostream>
#include <memory>

#include "circulo.hpp"

void imprime_figura(geom::figura f) {
  std::cout << f << "\n";
}
void imprime_circulo(geom::circulo c) {
  std::cout << c << "\n";
}

int main() {
  using namespace geom;
  std::cout << "umbral=" << 2* sizeof(void*) << "\n";
  figura f{1.5, 1.5};
  imprime_figura(f);
  circulo c{1.5, 1.5, 3.0};
  [[maybe_unused]] const figura * g = &c;
  auto p = std::make_unique<circulo>(1.5,1.5,4.0);
  std::unique_ptr<const figura> q = std::move(p);
  imprime_figura(*q);
  imprime_circulo(c);
}