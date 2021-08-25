#include "vecnum.hpp"

vecnum::vecnum(std::initializer_list<double> l)
    : tamanyo_{static_cast<int>(l.size())},
      capacidad_{tamanyo_},
      buffer_{std::make_unique_for_overwrite<double[]>(capacidad_)} {
  std::copy_n(l.begin(), l.size(), buffer_.get());
}

vecnum::vecnum(const vecnum & v)
    : tamanyo_{v.tamanyo_},
      capacidad_{v.capacidad_},
      buffer_{std::make_unique_for_overwrite<double[]>(capacidad_)} {
  std::copy_n(v.buffer_.get(), v.tamanyo_, buffer_.get());
}

vecnum & vecnum::operator=(const vecnum & v) {
  if (this == &v) { return *this; }
  auto aux = std::make_unique_for_overwrite<double[]>(v.capacidad_);
  std::copy_n(v.buffer_.get(), v.tamanyo_, aux.get());
  tamanyo_ = v.tamanyo_;
  capacidad_ = v.capacidad_;
  buffer_ = std::move(aux);
  return *this;
}

void vecnum::reserva(int n) {
  if (n > capacidad_) {
    auto aux = std::make_unique_for_overwrite<double[]>(n);
    std::copy_n(buffer_.get(), tamanyo_, aux.get());
    std::swap(buffer_, aux);
    capacidad_ = n;
  }
}

void vecnum::redimensiona(int n) {
  if (n < 0) { n = 0; }
  reserva(n);
  std::fill_n(buffer_.get() + tamanyo_, n - tamanyo_, 0.0);
  tamanyo_ = n;
}

void vecnum::agrega_final(double x) {
  constexpr int capacidad_inicial = 8;
  constexpr double factor = 1.8;

  if (capacidad_ == 0) {
    reserva(capacidad_inicial);
  } else {
    reserva(static_cast<int>(factor * capacidad_));
  }
  buffer_[tamanyo_++] = x;
}
