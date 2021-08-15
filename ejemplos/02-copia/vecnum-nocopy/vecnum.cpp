#include "vecnum.hpp"

#include <algorithm>

vecnum::vecnum(std::initializer_list<double> l)
    : tamanyo_ {static_cast<int>(l.size())}, buffer_ {new double[tamanyo_] {}} {
  std::copy(l.begin(), l.end(), buffer_);
}

std::ostream & operator<<(std::ostream & os, const vecnum & v) {
  if (v.tamanyo()>0) { os << v[0]; }
  for(int i=1; i<v.tamanyo(); ++i) {
    os << ", " << v[i];
  }
  return os;
}