//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2016-24, Lawrence Livermore National Security, LLC
// and RAJA project contributors. See the RAJA/LICENSE file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

///
/// Source file containing tests for Fraction
///

#include <RAJA/RAJA.hpp>
#include "RAJA_gtest.hpp"
#include <type_traits>

template < typename T >
void test_log2()
{
  ASSERT_EQ(RAJA::log2(T(257)), T(8));
  ASSERT_EQ(RAJA::log2(T(256)), T(8));
  ASSERT_EQ(RAJA::log2(T(255)), T(7));
  ASSERT_EQ(RAJA::log2(T(4)), T(2));
  ASSERT_EQ(RAJA::log2(T(3)), T(1));
  ASSERT_EQ(RAJA::log2(T(2)), T(1));
  ASSERT_EQ(RAJA::log2(T(1)), T(0));
  ASSERT_EQ(RAJA::log2(T(0)), T(0));
  if (std::is_signed<T>::value) {
    ASSERT_EQ(RAJA::log2(T(-1)), T(0));
    ASSERT_EQ(RAJA::log2(T(-100)), T(0));
  }
}

TEST(math, log2)
{
  test_log2<int>();
  test_log2<size_t>();
}


template < typename T >
void test_next_pow2()
{
  ASSERT_EQ(RAJA::next_pow2(T(257)), T(512));
  ASSERT_EQ(RAJA::next_pow2(T(256)), T(256));
  ASSERT_EQ(RAJA::next_pow2(T(255)), T(256));
  ASSERT_EQ(RAJA::next_pow2(T(4)), T(4));
  ASSERT_EQ(RAJA::next_pow2(T(3)), T(4));
  ASSERT_EQ(RAJA::next_pow2(T(2)), T(2));
  ASSERT_EQ(RAJA::next_pow2(T(1)), T(1));
  ASSERT_EQ(RAJA::next_pow2(T(0)), T(0));
  if (std::is_signed<T>::value) {
    ASSERT_EQ(RAJA::next_pow2(T(-1)), T(0));
    ASSERT_EQ(RAJA::next_pow2(T(-100)), T(0));
  }
}

TEST(math, next_pow2)
{
  test_next_pow2<int>();
  test_next_pow2<size_t>();
}


template < typename T >
void test_prev_pow2()
{
  ASSERT_EQ(RAJA::prev_pow2(T(257)), T(256));
  ASSERT_EQ(RAJA::prev_pow2(T(256)), T(256));
  ASSERT_EQ(RAJA::prev_pow2(T(255)), T(128));
  ASSERT_EQ(RAJA::prev_pow2(T(4)), T(4));
  ASSERT_EQ(RAJA::prev_pow2(T(3)), T(2));
  ASSERT_EQ(RAJA::prev_pow2(T(2)), T(2));
  ASSERT_EQ(RAJA::prev_pow2(T(1)), T(1));
  ASSERT_EQ(RAJA::prev_pow2(T(0)), T(0));
  if (std::is_signed<T>::value) {
    ASSERT_EQ(RAJA::prev_pow2(T(-1)), T(0));
    ASSERT_EQ(RAJA::prev_pow2(T(-100)), T(0));
  }
}

TEST(math, prev_pow2)
{
  test_prev_pow2<int>();
  test_prev_pow2<size_t>();
}
