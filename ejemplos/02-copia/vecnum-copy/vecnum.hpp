#ifndef VECNUM_COPY_VECNUM_HPP
#define VECNUM_COPY_VECNUM_HPP

#include <initializer_list>
#include <iostream>

class vecnum {
public:
  vecnum() : tamanyo_ {0}, buffer_ {nullptr} {}
  explicit vecnum(int n) : tamanyo_ {n}, buffer_ {new double[n] {}} {}
  vecnum(std::initializer_list<double> l);
  ~vecnum() { delete[] buffer_; }

  vecnum(const vecnum & v);
  vecnum & operator=(const vecnum & v);

  [[nodiscard]] int tamanyo() const { return tamanyo_; }

  double operator[](int i) const { return buffer_[i]; }
  double & operator[](int i) { return buffer_[i]; }

private:
  int tamanyo_;
  double * buffer_;
};

std::ostream & operator<<(std::ostream & os, const vecnum & v);

#endif// VECNUM_COPY_VECNUM_HPP
