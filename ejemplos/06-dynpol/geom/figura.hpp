#ifndef GEOM_FIGURA_HPP
#define GEOM_FIGURA_HPP

#include "punto.hpp"
#include <iosfwd>

namespace geom {

  class figura {
  public:
    explicit figura(punto p) : posicion_{p} {}

    [[nodiscard]] punto posicion() const noexcept { return posicion_; }
    [[nodiscard]] double x() const noexcept { return posicion_.x; }
    [[nodiscard]] double y() const noexcept { return posicion_.y; }

    void desplaza(desplazamiento d) noexcept { posicion_ += d; }

  private:
    punto posicion_;
  };

  std::ostream & operator<<(std::ostream & os, const figura & f);

}// namespace geom

#endif// GEOM_FIGURA_HPP
