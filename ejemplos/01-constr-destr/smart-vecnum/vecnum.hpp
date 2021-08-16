#ifndef SMART_VECNUM_HPP
#define SMART_VECNUM_HPP

#include <memory>

class vecnum {
public:
  explicit vecnum(int n) : tamanyo_{n}, buffer_{std::make_unique<double[]>(n)} {}

  [[nodiscard]] int tamanyo() const { return tamanyo_; }

  double operator[](int i) const { return buffer_[i]; }
  double &operator[](int i) { return buffer_[i]; }

private:
  int tamanyo_;
  std::unique_ptr<double[]> buffer_;
};

#endif//SMART_VECNUM_HPP