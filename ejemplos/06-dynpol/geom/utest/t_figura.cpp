#include <gtest/gtest.h>

#include "figura.hpp"

TEST(test_figura, constr) // NOLINT
{
  using namespace geom;
  figura f{punto{2.5, 1.5}};
  EXPECT_EQ((punto{2.5,1.5}), f.posicion());
  EXPECT_EQ(2.5, f.x());
  EXPECT_EQ(1.5, f.y());
}

TEST(test_figura, move) // NOLINT
{
  using namespace geom;
  figura f{punto{2.5, 1.5}};
  f.desplaza(1.0, -1.0);
  EXPECT_EQ((punto{3.5,0.5}), f.posicion());
  EXPECT_EQ(3.5, f.x());
  EXPECT_EQ(0.5, f.y());
}

