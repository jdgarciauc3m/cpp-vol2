#ifndef GEOM_PUNTO_HPP
#define GEOM_PUNTO_HPP

#include <iosfwd>

namespace geom {

  struct desplazamiento {
    double delta_x, delta_y;
  };

  struct punto {
    double x, y;
    bool operator==(const punto & p) const = default;
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

#endif// GEOM_PUNTO_HPP
