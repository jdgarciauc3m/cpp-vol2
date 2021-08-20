#include "vecnum.hpp"
#include <iostream>

vecnum::vecnum(std::initializer_list<double> l)
    : tamanyo_{static_cast<int>(l.size())}, buffer_{new double[tamanyo_]{}} {
  std::copy_n(l.begin(), l.size(), buffer_);
}

vecnum & vecnum::operator=(const vecnum & v) {
  std::cout << "vecnum::operator=(vecnum&)\n";
  if (this == &v) { return *this; }
  auto * aux = new double[v.tamanyo_]{};
  std::copy_n(v.buffer_, v.tamanyo_, aux);
  tamanyo_ = v.tamanyo_;
  buffer_ = aux;
  return *this;
}
vecnum::vecnum(vecnum && v) noexcept
    : tamanyo_{v.tamanyo_}, buffer_{v.buffer_} {
  std::cout << "vecnum(vecnum&&)\n";
  v.tamanyo_ = 0;
  v.buffer_ = nullptr;
}
vecnum & vecnum::operator=(vecnum && v) noexcept {
  std::cout << "vecnum::operator=(vecnum&&)\n";
  if (this == & v) return *this;
  delete []buffer_;
  tamanyo_ = v.tamanyo_;
  buffer_ = v.buffer_;
  v.tamanyo_ = 0;
  v.buffer_ = nullptr;
  return *this;
}

std::ostream & operator<<(std::ostream & os, const vecnum & v) {
  if (v.tamanyo() == 0) { return os; }
  os << v[0];
  for (int i = 1; i < v.tamanyo(); ++i) { os << ", " << v[i]; }
  return os;
}
