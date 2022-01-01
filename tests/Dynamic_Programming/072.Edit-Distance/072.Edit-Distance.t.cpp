#include "gtest/gtest.h"
#include <climits>   // INT_MAX
#include <algorithm> // std::min({})
#include <vector>
#include <string>
using namespace std;

#include <Dynamic_Programming/072.Edit-Distance/072.Edit-Distance.cpp>

TEST(edit_distance_72_test, I)
{
  std::string word1 = "horse";
  std::string word2 = "ros";

  ASSERT_EQ(Solution().minDistance2(word1, word2), 3);
  ASSERT_EQ(Solution().minDistance(word1, word2), 3);
}
