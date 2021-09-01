#include "circulo.hpp"
#include <numbers>
#include <ostream>

namespace geom {

  double circulo::area() const noexcept {
    return std::numbers::pi_v<double> * radio_ * radio_;
  }

  void circulo::inserta(std::ostream & os) const {
    os << "circulo: [";
    figura::inserta(os);
    os << " , " << radio() << "]";
  }

}// namespace geom
