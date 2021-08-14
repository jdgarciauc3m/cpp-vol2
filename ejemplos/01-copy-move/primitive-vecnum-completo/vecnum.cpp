#include "vecnum.hpp"

#include <algorithm>

vecnum::vecnum(std::initializer_list<double> l)
    : tamanyo_ {static_cast<int>(l.size())}, buffer_ {new double[tamanyo_] {}} {
  std::copy(l.begin(), l.end(), buffer_);
}
