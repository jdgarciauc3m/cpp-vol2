#include "figura.hpp"

#include <ostream>

namespace geom {

  std::ostream & operator<<(std::ostream & os, const punto & p) {
    return os << "[" << p.x << " , " << p.y << "]";
  }

  std::ostream & operator<<(std::ostream & os, const figura & f) {
    return os << "figura: " << f.posicion();
  }

}// namespace geom
