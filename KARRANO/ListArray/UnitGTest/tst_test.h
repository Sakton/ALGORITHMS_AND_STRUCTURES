#ifndef TST_TEST_H
#define TST_TEST_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "../../ListArray/listarray.h"

using namespace testing;

TEST(TestCase, Test)
{
  EXPECT_EQ(1, 1);
  ASSERT_THAT(0, Eq(0));
}

TEST( TestCase, T1 ) {
  ListArray la;
  ASSERT_TRUE( la.isEmpty( ) );
}

#endif // TST_TEST_H
