#ifndef GEOM2_PUNTO_HPP
#define GEOM2_PUNTO_HPP

#include <complex>
#include <iosfwd>

namespace geom {

  struct desplazamiento {
    double delta_x, delta_y;
    explicit desplazamiento(double dx) : delta_x{dx}, delta_y{} {}
    desplazamiento(double dx, double dy) : delta_x{dx}, delta_y{dy} {}
  };

  struct punto {
    double x, y;
    bool operator==(const punto & p) const noexcept = default;
    punto & operator+=(desplazamiento d) noexcept {
      x += d.delta_x;
      y += d.delta_y;
      return *this;
    }
  };

  inline punto operator+(punto p, desplazamiento d) noexcept {
    return {p.x + d.delta_x, p.y + d.delta_y};
  }

  std::ostream & operator<<(std::ostream & os, const punto & p);

}// namespace geom

#endif// GEOM2_PUNTO_HPP
