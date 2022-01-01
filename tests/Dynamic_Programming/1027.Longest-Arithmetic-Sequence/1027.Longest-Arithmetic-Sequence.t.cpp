#include "gtest/gtest.h"
#include <vector>
#include <string>
using namespace std;

#include <Dynamic_Programming/1027.Longest-Arithmetic-Sequence/1027.Longest-Arithmetic-Sequence.cpp>

TEST(longest_arithmetic_sequence_test, I)
{
  std::vector<int> arr{3,6,9,12};

  ASSERT_EQ(Solution().longestArithSeqLength(arr), 4);
}

TEST(longest_arithmetic_sequence_test, II)
{
  std::vector<int> arr{9,4,7,2,10};

  ASSERT_EQ(Solution().longestArithSeqLength(arr), 3);
}

TEST(longest_arithmetic_sequence_test, III)
{
  std::vector<int> arr{20,1,15,3,10,5,8};

  ASSERT_EQ(Solution().longestArithSeqLength(arr), 4);
}
