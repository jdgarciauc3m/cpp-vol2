#ifndef GEOM_CIRCULO_HPP
#define GEOM_CIRCULO_HPP

#include "figura.hpp"

namespace geom {

  class circulo : public figura {
  public:
    circulo(punto centro, double radio) noexcept
        : figura{centro},
          radio_{radio} {}

    [[nodiscard]] double radio() const noexcept { return radio_; }
    [[nodiscard]] double area() const noexcept;

  private:
    double radio_;
  };

  std::ostream & operator<<(std::ostream & os, const circulo & c);

}// namespace geom

#endif// GEOM_CIRCULO_HPP
