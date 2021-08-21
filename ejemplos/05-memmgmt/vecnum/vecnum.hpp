#ifndef VECNUM_VECNUM_HPP
#define VECNUM_VECNUM_HPP

#include <memory>

class vecnum {
public:
  vecnum() noexcept = default;
  explicit vecnum(int n)
      : capacidad_{std::max(0, n)},
        buffer_{std::make_unique<double[]>(capacidad_)} {}
  vecnum(std::initializer_list<double> l);

  vecnum(const vecnum & v);
  vecnum & operator=(const vecnum & v);

  vecnum(vecnum &&) noexcept = default;
  vecnum & operator=(vecnum &&) noexcept = default;

  ~vecnum() noexcept = default;

  void reserva(int n);
  void redimensiona(int n);
  void agrega_final(double x);

  [[nodiscard]] double operator[](int i) const noexcept { return buffer_[i]; }
  [[nodiscard]] double & operator[](int i) noexcept { return buffer_[i]; }

  [[nodiscard]] int tamanyo() const noexcept { return tamanyo_; }
  [[nodiscard]] int capacidad() const noexcept { return capacidad_; }

private:
  int tamanyo_ = 0;
  int capacidad_ = 0;
  std::unique_ptr<double[]> buffer_ = nullptr;
};

#endif// VECNUM_VECNUM_HPP
