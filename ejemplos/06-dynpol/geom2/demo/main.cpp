#include <circulo.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <diagrama.hpp>

#include "rectangulo.hpp"

void imprime(const geom::rectangulo & r) {
  std::cout << "centro: " << r.centro() << "\n"; // rectagulo::centro()
}

void imprime(const geom::figura & f) {
  std::cout << f << "\n";
  std::cout << "centro: " << f.centro() << "\n"; // figura::centro()
  std::cout << "area: " << f.area()  << "\n";
}

void imprime(const std::vector<std::unique_ptr<geom::figura>> & v) {
  for (const auto & f : v) {
    std::cout << *f << " -- area: " << f->area() << "\n";
  }
}

void imprime(const geom::diagrama & v) {
  for (const auto & f : v) {
    if (f) { std::cout << *f << " -- area: " << f->area(); }
    std::cout << "\n";
  }
}

int main() {
  using namespace geom;
  diagrama d(3);
  d.agrega_rectangulo(punto{1.0,1.0}, punto{3.5,2.5});
  d.agrega_circulo(punto{1.0,1.0}, 2.0);
  d.desplaza(desplazamiento{10.0,100});
  imprime(d);
}
