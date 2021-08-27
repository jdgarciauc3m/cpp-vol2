#include "figura.hpp"

#include <ostream>

namespace geom {

  std::ostream & operator<<(std::ostream & os, const figura & f) {
    return os << "figura: " << f.posicion();
  }

}// namespace geom
