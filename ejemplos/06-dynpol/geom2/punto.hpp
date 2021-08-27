#ifndef GEOM2_PUNTO_HPP
#define GEOM2_PUNTO_HPP

#include <complex>
#include <iosfwd>

namespace geom {

  struct desplazamiento {
    double delta_x;
    double delta_y;
  };

  struct punto {
    double x, y;
    bool operator==(const punto & p) const = default;
    punto & operator+=(desplazamiento d) {
      x += d.delta_x;
      y += d.delta_y;
      return *this;
    }
  };

  inline punto operator+(punto p, desplazamiento d) {
    return {p.x + d.delta_x, p.y + d.delta_y};
  }

  std::ostream & operator<<(std::ostream & os, const punto & p);

}// namespace geom

#endif// GEOM2_PUNTO_HPP
