#ifndef GEOM_CIRCULO_HPP
#define GEOM_CIRCULO_HPP

#include "figura.hpp"

namespace geom {

  class circulo : public figura {
  public:
    circulo(punto p, double r) : figura{p}, radio_{r} {}

    [[nodiscard]] double radio() const { return radio_; }
    [[nodiscard]] double area() const;

  private:
    double radio_;
  };

  std::ostream & operator<<(std::ostream & os, const circulo & c);

}// namespace geom

#endif// GEOM_CIRCULO_HPP
