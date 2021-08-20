#ifndef VECNUM_VECNUM_HPP
#define VECNUM_VECNUM_HPP

#include <algorithm>
#include <initializer_list>
#include <iostream>
class vecnum {
public:
  vecnum() = default;
  explicit vecnum(int n) : tamanyo_{n}, buffer_{new double[n]{}} {}
  vecnum(std::initializer_list<double> l);

  vecnum(const vecnum & v)
      : tamanyo_{v.tamanyo_}, buffer_{new double[tamanyo_]{}} {
    std::cout << "vecnum(vecnum&)\n";
    std::copy_n(v.buffer_, v.tamanyo_, buffer_);
  }
  vecnum & operator=(const vecnum & v);
  ~vecnum() { delete []buffer_; }

  vecnum(vecnum && v) noexcept;
  vecnum & operator=(vecnum && v) noexcept;

  [[nodiscard]] int tamanyo() const { return tamanyo_; }

  double operator[](int i) const { return buffer_[i]; }
  double & operator[](int i) { return buffer_[i]; }

private:
  int tamanyo_ = 0;
  double * buffer_ = nullptr;
};

std::ostream & operator<<(std::ostream & os, const vecnum & v);


#endif// VECNUM_VECNUM_HPP
