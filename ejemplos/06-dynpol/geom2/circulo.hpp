#ifndef GEOM2_CIRCULO_HPP
#define GEOM2_CIRCULO_HPP
#include "figura.hpp"

namespace geom {

  class circulo : public figura {
  public:
    circulo(punto centro, double radio) : figura{centro}, radio_{radio} {}

    [[nodiscard]] double radio() const { return radio_; }
    [[nodiscard]] double area() const;

  private:
    double radio_;
  };
  std::ostream & operator<<(std::ostream & os, const circulo & c);

}// namespace geom

#endif// GEOM2_CIRCULO_HPP
