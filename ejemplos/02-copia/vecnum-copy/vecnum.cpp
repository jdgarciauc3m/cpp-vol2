#include "vecnum.hpp"

#include <algorithm>

vecnum::vecnum(std::initializer_list<double> l)
    : tamanyo_ {static_cast<int>(l.size())}, buffer_ {new double[tamanyo_] {}}
{
  std::copy(l.begin(), l.end(), buffer_);
}

vecnum::vecnum(const vecnum & v)
    : tamanyo_ {v.tamanyo_}, buffer_ {new double[tamanyo_] {}}
{
  std::copy_n(v.buffer_, v.tamanyo_, buffer_);
}
vecnum & vecnum::operator=(const vecnum & v) {
  auto aux = new double[v.tamanyo_];
  std::copy_n(v.buffer_, v.tamanyo_, aux);

  tamanyo_ = v.tamanyo_;
  delete []buffer_;
  buffer_ = aux;

  return *this;
}

std::ostream & operator<<(std::ostream & os, const vecnum & v) {
  if (v.tamanyo() > 0) { os << v[0]; }
  for (int i = 1; i < v.tamanyo(); ++i) { os << ", " << v[i]; }
  return os;
}