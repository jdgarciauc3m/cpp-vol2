#ifndef GEOM_FIGURA_HPP
#define GEOM_FIGURA_HPP

#include <iosfwd>

namespace geom {

  struct punto {
    double x, y;
    void desplaza(double delta_x, double delta_y) {
      x += delta_x;
      y += delta_y;
    }
    bool operator==(const punto & p) const = default;
  };

  std::ostream & operator<<(std::ostream & os, const punto & p);

  class figura {
  public:
    explicit figura(punto p) : posicion_{p} {}

    [[nodiscard]] punto posicion() const { return posicion_; }
    [[nodiscard]] double x() const { return posicion_.x; }
    [[nodiscard]] double y() const { return posicion_.y; }

    void desplaza(double dx, double dy) { posicion_.desplaza(dx, dy); }

  private:
    punto posicion_;
  };

  std::ostream & operator<<(std::ostream & os, const figura & f);

}// namespace geom

#endif// GEOM_FIGURA_HPP
