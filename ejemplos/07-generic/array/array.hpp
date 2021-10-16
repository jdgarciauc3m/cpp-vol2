#ifndef ARRAY_ARRAY_HPP
#define ARRAY_ARRAY_HPP

namespace cont {
  template <typename T, int N>
  struct array {
    T vec[N];

    T & operator[](int i) { return vec[i]; }
    const T & operator[](int i) const { return vec[i]; }

    int tamanyo() const { return N; }
  };
}// namespace cont

#endif// ARRAY_ARRAY_HPP
