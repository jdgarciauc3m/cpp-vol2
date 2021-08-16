#include <gtest/gtest.h>

#include "vecnum.hpp"

TEST(vecnum_ctor_defecto, constructor) {
  vecnum v;
  EXPECT_EQ(v.tamanyo(), 0);
}

TEST(vecnum_ctor_tamanyo, tam_cero) {
  vecnum v(0);
  EXPECT_EQ(0, v.tamanyo());
}

TEST(vecnum_ctor_tamanyo, tam_positivo) {
  vecnum v(3);
  ASSERT_EQ(3, v.tamanyo());
  for (int i=0; i<3; ++i) {
    EXPECT_EQ(0, v[i]);
  }
}

TEST(vecnum_ctor_lista, vacia) {
  std::initializer_list<double> l{};
  vecnum v{l};
  ASSERT_EQ(0, v.tamanyo());
}

TEST(vecnum_ctor_lista, un_elemento) {
  vecnum v{3};
  ASSERT_EQ(v.tamanyo(), 1);
  EXPECT_EQ(3, v[0]);
}

TEST(vecnum_ctor_lista, varios_elementos) {
  vecnum v{3,4,5};
  ASSERT_EQ(v.tamanyo(), 3);
  EXPECT_EQ(3, v[0]);
  EXPECT_EQ(4, v[1]);
  EXPECT_EQ(5, v[2]);
}

TEST(vecnum_ctor_copia, normal) {
  vecnum v{3,4,5};
  vecnum w{v};
  ASSERT_EQ(3, w.tamanyo());
  EXPECT_EQ(3, w[0]);
  EXPECT_EQ(4, w[1]);
  EXPECT_EQ(5, w[2]);
}

TEST(vecnum_ctor_copia, vacio) {
  vecnum v{};
  vecnum w{v};
  ASSERT_EQ(0, w.tamanyo());
}

TEST(vecnum_asigna_copia, normal) {
  vecnum v{3,4,5};
  vecnum w;
  w = v;
  ASSERT_EQ(3, w.tamanyo());
  EXPECT_EQ(3, w[0]);
  EXPECT_EQ(4, w[1]);
  EXPECT_EQ(5, w[2]);
}

TEST(vecnum_asigna_copia, vacio) {
  vecnum v{};
  vecnum w;
  w = v;
  ASSERT_EQ(0, w.tamanyo());
}

TEST(vecnum_acceso, lectura) {
  const vecnum v{1};
  ASSERT_EQ(1, v[0]);
}

TEST(vecnum_acceso, escritura) {
  vecnum v{1};
  v[0] = 42;
  ASSERT_EQ(42, v[0]);
}

TEST(vecnum_flujo_inserta, normal) {
  std::ostringstream os;
  vecnum v{1,2,3};;
  os << v;
  std::string s = os.str();
  EXPECT_EQ(s, "1, 2, 3");
}
