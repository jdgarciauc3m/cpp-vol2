#ifndef GEOM2_DIAGRAMA_HPP
#define GEOM2_DIAGRAMA_HPP

#include "figura.hpp"
#include "rectangulo.hpp"
#include <memory>
#include <vector>

namespace geom {

  class diagrama : private std::vector<std::shared_ptr<figura>> {
  public:
    using std::vector<std::shared_ptr<figura>>::vector;

    void agrega_circulo(punto c, double r) {
      push_back(std::make_unique<circulo>(c, r));
    }

    void agrega_rectangulo(punto p1, punto p2) {
      push_back(std::make_unique<rectangulo>(p1, p2));
    }

    void desplaza(desplazamiento d) {
      for (auto & x : *this) {
        if (x) x->desplaza(d);
      }
    }
  };

}// namespace geom
#endif// GEOM2_DIAGRAMA_HPP
