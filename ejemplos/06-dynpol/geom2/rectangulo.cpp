#include "rectangulo.hpp"

namespace geom {

  void rectangulo::inserta(std::ostream & os) const {
    os << "rectangulo: [";
    figura::inserta(os);
    os << "] , " << ancho() << " , " << alto() << " ]";
  }

}