#ifndef GEOM2_CIRCULO_HPP
#define GEOM2_CIRCULO_HPP
#include "figura.hpp"

namespace geom {

  class circulo : public figura {
  public:
    circulo(geom::punto centro, double radio) noexcept
        : figura{centro},
          radio_{radio} {}

    [[nodiscard]] double radio() const noexcept { return radio_; }
    [[nodiscard]] double area() const noexcept override;

    using figura::desplaza;
    void desplaza(double delta) noexcept { figura::desplaza({delta, delta}); }

    void refleja_x() noexcept override { posicion_.x = -posicion_.x; }
    void inserta(std::ostream & os) const override;

  private:
    [[nodiscard]] circulo * clona_impl() const override {
      return new circulo{*this};
    }

  private:
    double radio_;
  };

}// namespace geom

#endif// GEOM2_CIRCULO_HPP
