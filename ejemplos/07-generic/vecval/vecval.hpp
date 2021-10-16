#ifndef CONT_VECVAL_HPP
#define CONT_VECVAL_HPP

#include <memory>

namespace cont {// Containers library

  template <typename T>
  class vecvalues {
  public:
    vecvalues() noexcept = default;
    explicit vecvalues(int n);
    vecvalues(std::initializer_list<T> list);

    vecvalues(const vecvalues & otro);
    vecvalues & operator=(const vecvalues & otro);

    vecvalues(vecvalues &&) noexcept = default;
    vecvalues & operator=(vecvalues &&) noexcept = default;

    ~vecvalues() noexcept = default;

    void reserva(int n);
    void redimensiona(int n);
    void agrega_final(T valor);

    [[nodiscard]] T operator[](int i) const noexcept { return buffer_[i]; }
    [[nodiscard]] T & operator[](int i) noexcept { return buffer_[i]; }

    [[nodiscard]] int tamanyo() const noexcept { return tamanyo_; }
    [[nodiscard]] int capacidad() const noexcept { return capacidad_; }

  private:
    int tamanyo_ = 0;
    int capacidad_ = 0;
    std::unique_ptr<T[]> buffer_ = nullptr;
  };

  template <typename T>
  vecvalues<T>::vecvalues(int n)
      : tamanyo_{std::max(0,n)},
        capacidad_{tamanyo_},
        buffer_{std::make_unique<T[]>(capacidad_)} {}

  template <typename T>
  vecvalues<T>::vecvalues(std::initializer_list<T> list)
      : tamanyo_{static_cast<int>(list.size())},
        capacidad_{tamanyo_},
        buffer_{std::make_unique_for_overwrite<T[]>(capacidad_)}
  {
    std::copy_n(list.begin(), list.size(), buffer_.get());
  }

  template <typename T>
  vecvalues<T>::vecvalues(const vecvalues & otro)
      : tamanyo_{otro.tamanyo_},
        capacidad_{otro.capacidad_},
        buffer_{std::make_unique_for_overwrite<T[]>(capacidad_)} {
    std::copy_n(otro.buffer_.get(), otro.tamanyo_, buffer_.get());
  }

  template <typename T>
  vecvalues<T> & vecvalues<T>::operator=(const vecvalues & otro) {
    if (this == &otro) { return *this; }
    auto aux = std::make_unique_for_overwrite<T[]>(otro.capacidad_);
    std::copy_n(otro.buffer_.get(), otro.tamanyo_, aux.get());
    tamanyo_ = otro.tamanyo_;
    capacidad_ = otro.capacidad_;
    buffer_ = std::move(aux);
    return *this;
  }

  template <typename T>
  void vecvalues<T>::reserva(int n) {
    if (n > capacidad_) {
      auto aux = std::make_unique_for_overwrite<T[]>(n);
      std::copy_n(buffer_.get(), tamanyo_, aux.get());
      std::swap(buffer_, aux);
      capacidad_ = n;
    }
  }

  template <typename T>
  void vecvalues<T>::redimensiona(int n) {
    if (n < 0) { n = 0; }
    reserva(n);
    std::fill_n(buffer_.get() + tamanyo_, n - tamanyo_, 0.0);
    tamanyo_ = n;
  }

  template <typename T>
  void vecvalues<T>::agrega_final(T valor) {
    constexpr int capacidad_inicial = 8;
    constexpr double factor = 1.8;

    if (capacidad_ == 0) {
      reserva(capacidad_inicial);
    } else {
      reserva(static_cast<int>(factor * capacidad_));
    }
    buffer_[tamanyo_++] = valor;
  }


}// namespace cont

#endif// VECVAL_VECVAL_HPP
