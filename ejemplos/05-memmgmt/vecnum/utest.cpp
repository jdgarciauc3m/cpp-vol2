#include <gtest/gtest.h>

#include "vecnum.hpp"

TEST(vecnum_ctor_defecto, constructor) {// NOLINT
  vecnum v;
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
}

TEST(vecnum_ctor_tamanyo, tamanyo_cero) {// NOLINT
  vecnum v(0);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
}

TEST(vecnum_ctor_tamanyo, tamanyo_positivo) {// NOLINT
  vecnum v(2);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(2, v.capacidad());
}

TEST(vecnum_ctor_tamanyo, tamanyo_negativo) {// NOLINT
  vecnum v(-2);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
}

TEST(vecnum_ctor_lista, lista_valores) {// NOLINT
  vecnum v{1, 2, 3};
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(2, v[1]);
  EXPECT_EQ(3, v[2]);
}

TEST(vecnum_ctor_copia, vacio) {// NOLINT
  vecnum v;
  vecnum w = v;
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
  EXPECT_EQ(0, w.tamanyo());
  EXPECT_EQ(0, w.capacidad());
}

TEST(vecnum_ctor_copia, lista) {// NOLINT
  vecnum v{1, 2, 3};
  vecnum w = v;
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(2, v[1]);
  EXPECT_EQ(3, v[2]);
  EXPECT_EQ(3, w.tamanyo());
  EXPECT_EQ(3, w.capacidad());
  EXPECT_EQ(1, w[0]);
  EXPECT_EQ(2, w[1]);
  EXPECT_EQ(3, w[2]);
}

TEST(vecnum_ctor_copia, copia_lista_con_reserva) {// NOLINT
  vecnum v{1, 2, 3};
  v.reserva(10);
  vecnum w = v;
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(10, v.capacidad());
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(2, v[1]);
  EXPECT_EQ(3, v[2]);
  EXPECT_EQ(3, w.tamanyo());
  EXPECT_EQ(10, w.capacidad());
  EXPECT_EQ(1, w[0]);
  EXPECT_EQ(2, w[1]);
  EXPECT_EQ(3, w[2]);
}

TEST(vecnum_asignacion_copia, vacio) { // NOLINT
  vecnum v;
  vecnum w{1.5, 2.5, 3.5};
  w = v;
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
  EXPECT_EQ(0, w.tamanyo());
  EXPECT_EQ(0, w.capacidad());
}

TEST(vecnum_asignacion_copia, copia_lista) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  vecnum w;
  w = v;
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
  EXPECT_DOUBLE_EQ(1.5, v[0]);
  EXPECT_DOUBLE_EQ(2.5, v[1]);
  EXPECT_DOUBLE_EQ(3.5, v[2]);
  EXPECT_EQ(3, w.tamanyo());
  EXPECT_EQ(3, w.capacidad());
  EXPECT_DOUBLE_EQ(1.5, w[0]);
  EXPECT_DOUBLE_EQ(2.5, w[1]);
  EXPECT_DOUBLE_EQ(3.5, w[2]);
}

TEST(vecnum_asignacion_copia, copia_lista_con_reserva) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  v.reserva(10);
  vecnum w;
  w = v;
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(10, v.capacidad());
  EXPECT_DOUBLE_EQ(1.5, v[0]);
  EXPECT_DOUBLE_EQ(2.5, v[1]);
  EXPECT_DOUBLE_EQ(3.5, v[2]);
  EXPECT_EQ(3, w.tamanyo());
  EXPECT_EQ(10, w.capacidad());
  EXPECT_DOUBLE_EQ(1.5, w[0]);
  EXPECT_DOUBLE_EQ(2.5, w[1]);
  EXPECT_DOUBLE_EQ(3.5, w[2]);
}

TEST(vecnum_ctor_movimiento, vacio) { // NOLINT
  vecnum v;
  vecnum w{std::move(v)};
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
  EXPECT_EQ(0, w.tamanyo());
  EXPECT_EQ(0, w.capacidad());
}

TEST(vecnum_ctor_movimiento, lista) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  vecnum w = std::move(v);
  EXPECT_EQ(3, w.tamanyo());
  EXPECT_EQ(3, w.capacidad());
  EXPECT_DOUBLE_EQ(1.5, w[0]);
  EXPECT_DOUBLE_EQ(2.5, w[1]);
  EXPECT_DOUBLE_EQ(3.5, w[2]);
}

TEST(vecnum_ctor_movimiento, lista_con_reserva) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  v.reserva(10);
  vecnum w = std::move(v);
  EXPECT_EQ(3, w.tamanyo());
  EXPECT_EQ(10, w.capacidad());
  EXPECT_DOUBLE_EQ(1.5, w[0]);
  EXPECT_DOUBLE_EQ(2.5, w[1]);
  EXPECT_DOUBLE_EQ(3.5, w[2]);
}

TEST(vecnum_asignacion_movimiento, vacio) { // NOLINT
  vecnum v;
  vecnum w{1.5, 2.5, 3.5};
  w = std::move(v);
  EXPECT_EQ(0, w.tamanyo());
  EXPECT_EQ(0, w.capacidad());
}

TEST(vecnum_asignacion_movimiento, lista) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  vecnum w;
  w = std::move(v);
  EXPECT_EQ(3, w.tamanyo());
  EXPECT_EQ(3, w.capacidad());
  EXPECT_DOUBLE_EQ(1.5, w[0]);
  EXPECT_DOUBLE_EQ(2.5, w[1]);
  EXPECT_DOUBLE_EQ(3.5, w[2]);
}

TEST(vecnum_asignacion_movimiento, lista_con_reserva) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  v.reserva(10);
  vecnum w;
  w = std::move(v);
  EXPECT_EQ(3, w.tamanyo());
  EXPECT_EQ(10, w.capacidad());
  EXPECT_DOUBLE_EQ(1.5, w[0]);
  EXPECT_DOUBLE_EQ(2.5, w[1]);
  EXPECT_DOUBLE_EQ(3.5, w[2]);
}

TEST(vecnum_vacio_reserva, cero) {// NOLINT
  vecnum v;
  v.reserva(0);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
}

TEST(vecnum_vacio_reserva, negativo) {// NOLINT
  vecnum v;
  v.reserva(-3);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
}

TEST(vecnum_vacio_reserva, positivo) {// NOLINT
  vecnum v;
  v.reserva(3);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
}

TEST(vecnum_lista_reserva, cero) {// NOLINT
  vecnum v{1, 2, 3};
  v.reserva(0);
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
}

TEST(vecnum_lista_reserva, negativo) {// NOLINT
  vecnum v{1, 2, 3};
  v.reserva(-2);
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
}

TEST(vecnum_lista_reserva, corto) {// NOLINT
  vecnum v{1, 2, 3};
  v.reserva(2);
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
}

TEST(vecnum_lista_reserva, largo) {// NOLINT
  vecnum v{1, 2, 3};
  v.reserva(4);
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(4, v.capacidad());
}

TEST(vecnum_vacio_redimensiona, cero) {// NOLINT
  vecnum v;
  v.redimensiona(0);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
}

TEST(vecnum_vacio_redimensiona, negativo) {// NOLINT
  vecnum v;
  v.redimensiona(-3);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(0, v.capacidad());
}

TEST(vecnum_vacio_redimensiona, positivo) {// NOLINT
  vecnum v;
  v.redimensiona(3);
  EXPECT_EQ(3, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
  EXPECT_DOUBLE_EQ(0.0, v[0]);
  EXPECT_DOUBLE_EQ(0.0, v[1]);
  EXPECT_DOUBLE_EQ(0.0, v[2]);
}

TEST(vecnum_lista_redimensiona, cero) {// NOLINT
  vecnum v{1, 2, 3};
  v.redimensiona(0);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
}

TEST(vecnum_lista_redimensiona, negativo) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  v.redimensiona(-2);
  EXPECT_EQ(0, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
}

TEST(vecnum_lista_redimensiona, corto) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  v.redimensiona(2);
  EXPECT_EQ(2, v.tamanyo());
  EXPECT_EQ(3, v.capacidad());
  EXPECT_DOUBLE_EQ(1.5, v[0]);
  EXPECT_DOUBLE_EQ(2.5, v[1]);
}

TEST(vecnum_lista_redimensiona, largo) {// NOLINT
  vecnum v{1.5, 2.5, 3.5};
  v.redimensiona(4);
  EXPECT_EQ(4, v.tamanyo());
  EXPECT_EQ(4, v.capacidad());
  EXPECT_DOUBLE_EQ(1.5, v[0]);
  EXPECT_DOUBLE_EQ(2.5, v[1]);
  EXPECT_DOUBLE_EQ(3.5, v[2]);
  EXPECT_DOUBLE_EQ(0.0, v[3]);
}

TEST(vecnum_agrega_final, vacio) { // NOLINT
  vecnum v;
  v.agrega_final(1.5);
  EXPECT_EQ(1, v.tamanyo());
  EXPECT_LE(1, v.capacidad());
  EXPECT_DOUBLE_EQ(1.5, v[0]);
}

TEST(vecnum_agrega_final, lista) { // NOLINT
  vecnum v{1.5, 2.5, 3.5};
  v.agrega_final(3.14);
  EXPECT_EQ(4, v.tamanyo());
  EXPECT_LE(4, v.capacidad());
  EXPECT_DOUBLE_EQ(1.5, v[0]);
  EXPECT_DOUBLE_EQ(2.5, v[1]);
  EXPECT_DOUBLE_EQ(3.5, v[2]);
  EXPECT_DOUBLE_EQ(3.14, v[3]);
}