#ifndef PRIMITIVE_VECNUM_DESTR_VECNUM_HPP
#define PRIMITIVE_VECNUM_DESTR_VECNUM_HPP

class vecnum {
public:
  explicit vecnum(int n) : tamanyo_{n}, buffer_{new double[n]{}} {}
  ~vecnum() { delete []buffer_; }

  [[nodiscard]] int tamanyo() const { return tamanyo_; }

  double operator[](int i) const { return buffer_[i]; }
  double &operator[](int i) { return buffer_[i]; }

private:
  int tamanyo_;
  double * buffer_;
};

#endif//PRIMITIVE_VECNUM_DESTR_VECNUM_HPP
