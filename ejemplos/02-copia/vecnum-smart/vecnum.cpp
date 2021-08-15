#include "vecnum.hpp"

#include <algorithm>

vecnum::vecnum(std::initializer_list<double> l)
    : tamanyo_ {static_cast<int>(l.size())},
      buffer_ {std::make_unique<double[]>(l.size())} {
  std::copy_n(l.begin(), l.size(), buffer_.get());
}

vecnum::vecnum(const vecnum & v)
    : tamanyo_ {v.tamanyo_}, buffer_ {std::make_unique<double[]>(v.tamanyo_)} {
  std::copy_n(v.buffer_.get(), v.tamanyo_, buffer_.get());
}

vecnum & vecnum::operator=(const vecnum & v) {
  tamanyo_ = v.tamanyo_;
  buffer_ = std::make_unique<double[]>(v.tamanyo_);
  std::copy_n(v.buffer_.get(), v.tamanyo_, buffer_.get());
  return *this;
}

std::ostream & operator<<(std::ostream & os, const vecnum & v) {
  if (v.tamanyo() <= 0) { return os; }
  os << v[0];
  for (int i = 1; i < v.tamanyo(); ++i) { os << ", " << v[i]; }
  return os;
}
