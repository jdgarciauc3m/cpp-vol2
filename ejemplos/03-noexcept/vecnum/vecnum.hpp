#ifndef VECNUM_VECNUM_HPP
#define VECNUM_VECNUM_HPP

#include <memory>

class vecnum {
public:
  vecnum() noexcept = default;
  explicit vecnum(int n)
  : tamanyo_ {n}, buffer_ {std::make_unique<double[]>(n)} {}
  vecnum(std::initializer_list<double> l);

  vecnum(const vecnum & v);
  vecnum & operator=(const vecnum & v);

  [[nodiscard]] int tamanyo() const noexcept { return tamanyo_; }

  double operator[](int i) const noexcept { return buffer_[i]; }
  double & operator[](int i) noexcept { return buffer_[i]; }

private:
  int tamanyo_ = 0;
  std::unique_ptr<double[]> buffer_ {};
};

std::ostream & operator<<(std::ostream & os, const vecnum & v);

#endif// VECNUM_VECNUM_HPP
