#include "gtest/gtest.h"
#include <climits>   // INT_MAX
#include <algorithm> // std::min({})
#include <vector>
#include <string>
using namespace std;

#include <unistd.h>
#include <ctime>

#include <chrono> // benchmark

#include <Dynamic_Programming/072.Edit-Distance/072.Edit-Distance.cpp>

TEST(edit_distance_72_test, I)
{
  std::string word1 = "horse";
  std::string word2 = "ros";

  ASSERT_EQ(Solution().minDistance2(word1, word2), 3);
  ASSERT_EQ(Solution().minDistance(word1, word2), 3);
}

TEST(edit_distance_72_test, II)
{
  std::string word1 = "intention";
  std::string word2 = "execution";

  ASSERT_EQ(Solution().minDistance2(word1, word2), 5);
  ASSERT_EQ(Solution().minDistance(word1, word2), 5);
}

TEST(edit_distance_72_test, benchmark)
{
  static std::string alnums =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

  static std::size_t len = 1000;

  std::string rand1;
  rand1.reserve(len);

  for (auto i = 0; i != len; ++i)
    rand1.append(1, alnums[rand() % alnums.size()]);

  std::string rand2;
  rand2.reserve(len);

  for (auto i = 0; i != len; ++i)
    rand2.append(1, alnums[rand() % alnums.size()]);

  int ed1 = 0;
  int ed2 = 0;
  Solution s;

  {
    auto start = chrono::steady_clock::now();
    ed1 = s.minDistance(rand1, rand2);
    auto end = chrono::steady_clock::now();

    printf("time cost of minDistance is %ld [ms]\n",
           chrono::duration_cast<chrono::milliseconds>(end - start).count());
  }

  {
    auto start = chrono::steady_clock::now();
    ed2 = s.minDistance2(rand1, rand2);
    auto end = chrono::steady_clock::now();

    printf("time cost of minDistance2 is %ld [ms]\n",
           chrono::duration_cast<chrono::milliseconds>(end - start).count());
  }

  ASSERT_EQ(ed1, ed2);
}