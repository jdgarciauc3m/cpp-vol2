#ifndef GEOM2_FIGURA_HPP
#define GEOM2_FIGURA_HPP

#include "punto.hpp"

#include <iosfwd>

namespace geom {

  class figura {
  public:
    explicit figura(punto p) : posicion_{p} {}

    [[nodiscard]] punto posicion() const { return posicion_; }
    [[nodiscard]] punto centro() const { return posicion_; }
    [[nodiscard]] double x() const { return posicion_.x; }
    [[nodiscard]] double y() const { return posicion_.y; }

    void desplaza(double delta_x, double delta_y) {
      posicion_ += desplazamiento{delta_x,delta_y}; }

  private:
    punto posicion_;
  };

  std::ostream & operator<<(std::ostream & os, const figura & f);

}// namespace geom

#endif// GEOM2_FIGURA_HPP