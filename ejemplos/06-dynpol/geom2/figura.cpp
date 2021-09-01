#include "figura.hpp"

#include <ostream>

namespace geom {

  void figura::inserta(std::ostream & os) const {
    os << "figura: " << posicion_;
  }

  std::ostream & operator<<(std::ostream & os, const figura & f) {
    f.inserta(os);
    return os;
  }

}// namespace geom
