#include "rectangulo.hpp"

namespace geom {

  std::ostream & operator<<(std::ostream & os, const rectangulo & r) {
    os << "rectangulo: [";
    os << static_cast<const figura&>(r);
    return os << "] , " << r.ancho() << " , " << r.alto() << " ]";
  }
}