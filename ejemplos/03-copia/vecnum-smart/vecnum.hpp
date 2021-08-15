#ifndef VECNUM_SMART_VECNUM_HPP
#define VECNUM_SMART_VECNUM_HPP

#include <initializer_list>
#include <memory>

class vecnum {
public:
  vecnum() = default;
  explicit vecnum(int n)
      : tamanyo_ {n}, buffer_ {std::make_unique<double[]>(n)} {}
  vecnum(std::initializer_list<double> l);

  vecnum(const vecnum & v);
  vecnum & operator=(const vecnum & v);

  [[nodiscard]] int tamanyo() const { return tamanyo_; }

  double operator[](int i) const { return buffer_[i]; }
  double & operator[](int i) { return buffer_[i]; }

private:
  int tamanyo_ = 0;
  std::unique_ptr<double[]> buffer_ {};
};

std::ostream & operator<<(std::ostream & os, const vecnum & v);

#endif// VECNUM_SMART_VECNUM_HPP
