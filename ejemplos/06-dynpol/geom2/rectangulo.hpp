#ifndef GEOM2_RECTANGULO_HPP
#define GEOM2_RECTANGULO_HPP

#include "figura.hpp"

namespace geom {
  class rectangulo : public figura {
  public:
    rectangulo(punto a, punto b) noexcept
        : figura(a),
          ancho_{b.x - a.x},
          alto_{b.y - a.y} {}

    [[nodiscard]] double ancho() const noexcept { return ancho_; }
    [[nodiscard]] double alto() const noexcept { return alto_; }
    [[nodiscard]] double area() const noexcept override {
      return ancho_ * alto_;
    }

    [[nodiscard]] punto centro() const noexcept override {
      return figura::centro() + desplazamiento{ancho_ / 2, alto_ / 2};
    }

    void refleja_x() noexcept override { posicion_.x = - posicion_.x - ancho_; }

    void inserta(std::ostream & os) const override;

  private:
    [[nodiscard]] rectangulo * clona_impl() const override {
      return new rectangulo{*this};
    }

  private:
    double ancho_;
    double alto_;
  };

}// namespace geom

#endif// GEOM2_RECTANGULO_HPP
