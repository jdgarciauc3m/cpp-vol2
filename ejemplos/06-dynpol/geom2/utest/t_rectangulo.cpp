#include "rectangulo.hpp"

#include <gtest/gtest.h>

TEST(test_rectangulo, constr)// NOLINT
{
  using namespace geom;
  rectangulo r{punto{2.5, 1.5}, punto{3.0, 3.0}};
  EXPECT_EQ((punto{2.75,2.25}), r.centro());
  EXPECT_EQ(0.5, r.ancho());
  EXPECT_EQ(1.5, r.alto());
}

TEST(test_rectangulo, clonacion) // NOLINT
{
  using namespace geom;
  rectangulo c{punto{1.0,1.0}, punto{3.0,5.0}};
  figura & f = c;
  auto d = f.clona();
  EXPECT_EQ((punto{2.0,3.0}), d->centro());
}


TEST(test_rectangulo, desplaza)// NOLINT
{
  using namespace geom;
  rectangulo r{punto{2.5, 2.5}, punto{3.0, 3.0}};
  r.desplaza(desplazamiento{1.0, -1.0});
  EXPECT_EQ((punto{3.75, 1.75}), r.centro());
  EXPECT_EQ(0.5, r.ancho());
  EXPECT_EQ(0.5, r.alto());
}

TEST(test_rectangulo, area)// NOLINT
{
  using namespace geom;
  rectangulo r{punto{2.5, 2.5}, punto{3.0, 3.0}};
  EXPECT_EQ(0.25, r.area());
}

TEST(test_rectangulo, insercion_flujo)// NOLINT
{
  using namespace geom;
  rectangulo r{punto{2.5, 1.5}, punto{3.0, 3.0}};
  std::ostringstream os;
  os << r;
  EXPECT_STREQ("rectangulo: [figura: [2.5 , 1.5]] , 0.5 , 1.5 ]",
               os.str().c_str());
}

TEST(test_rectangulo, simetria_x) // NOLINT
{
  using namespace geom;
  rectangulo r{punto{1.0,2.0}, {5.0,5.0}};
  r.refleja_x();
  EXPECT_EQ((punto{-3.0,3.5}), r.centro());
}