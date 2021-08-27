#ifndef GEOM2_RECTANGULO_HPP
#define GEOM2_RECTANGULO_HPP

#include "figura.hpp"

namespace geom {
  class rectangulo : public figura {
  public:
    rectangulo(punto a, punto b)
        : figura(a),
          ancho_{b.x - a.x},
          alto_{b.y - a.y} {}

    [[nodiscard]] double ancho() const { return ancho_; }
    [[nodiscard]] double alto() const { return alto_; }
    [[nodiscard]] double area() const { return ancho_ * alto_; }

    [[nodiscard]] punto centro() const {
      return figura::centro() + desplazamiento{ancho_/2,alto_/2};
    }

  private:
    double ancho_;
    double alto_;
  };

  std::ostream & operator<<(std::ostream & os, const rectangulo & r);

}// namespace geom

#endif// GEOM2_RECTANGULO_HPP
