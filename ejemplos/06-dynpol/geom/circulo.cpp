#include "circulo.hpp"
#include "figura.hpp"
#include <numbers>
#include <ostream>

namespace geom {

  double circulo::area() const noexcept {
    return std::numbers::pi_v<double> * radio_ * radio_;
  }

  std::ostream & operator<<(std::ostream & os, const circulo & c) {
    return os << "circulo: [" << c.posicion() << " , " << c.radio() << "]";
  }

}// namespace geom
