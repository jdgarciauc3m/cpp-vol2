#ifndef PRIMITIVE_VECNUM_COMPLETO_HPP
#define PRIMITIVE_VECNUM_COMPLETO_HPP

#include <initializer_list>

class vecnum {
public:
  vecnum() : tamanyo_{0}, buffer_{nullptr} {}
  explicit vecnum(int n) : tamanyo_{n}, buffer_{new double[n]{}} {}
  vecnum(std::initializer_list<double> l);
  ~vecnum() { delete []buffer_; }

  [[nodiscard]] int tamanyo() const { return tamanyo_; }

  double operator[](int i) const { return buffer_[i]; }
  double &operator[](int i) { return buffer_[i]; }

private:
  int tamanyo_;
  double * buffer_;
};

#endif//PRIMITIVE_VECNUM_COMPLETO_HPP
