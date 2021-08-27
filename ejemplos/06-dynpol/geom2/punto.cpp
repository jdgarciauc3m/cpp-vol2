#include "punto.hpp"
#include <ostream>

namespace geom {

  std::ostream & operator<<(std::ostream & os, const punto & p) {
    return os << "[" << p.x << " , " << p.y << "]";
  }

}// namespace geom
