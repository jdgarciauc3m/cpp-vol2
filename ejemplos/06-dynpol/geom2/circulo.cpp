#include "circulo.hpp"
#include "punto.hpp"
#include <numbers>
#include <ostream>

namespace geom {

  double circulo::area() const {
    return std::numbers::pi_v<double> * radio_ * radio_;
  }

  std::ostream & operator<<(std::ostream & os, const circulo & c) {
    os << "circulo: [";
    os << static_cast<const figura&>(c);
    return os << " , " << c.radio() << "]";
  }

}// namespace geom
