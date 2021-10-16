#include <gtest/gtest.h>
#include "vecval.hpp"

TEST(ut_vecval, construct_size)
{
  cont::vecvalues<double> v(5);
  EXPECT_EQ(5, v.tamanyo());
  EXPECT_EQ(5, v.capacidad());
  for (int i=0; i<5;++i) {
    EXPECT_EQ(0, v[i]);
  }
}