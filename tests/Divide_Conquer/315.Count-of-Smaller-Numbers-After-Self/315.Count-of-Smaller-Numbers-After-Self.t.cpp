#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
using namespace std;

#include <unistd.h>
#include <ctime>

#include <chrono> // benchmark


#include <Divide_Conquer/315.Count-of-Smaller-Numbers-After-Self/315.Count-of-Smaller-Numbers-After-Self.cpp>

TEST(count_of_smaller_numbers_after_self, consistency)
{
  Solution s;

  std::vector<int> nums{5,2,6,1};
  std::vector<int> expected{2,1,1,0};

  ASSERT_EQ(s.countSmaller(nums), expected);
  ASSERT_EQ(s.count_smaller_binary_indexed_tree(nums), expected);
}

TEST(count_of_smaller_numbers_after_self, benchmark)
{
  std::vector<int> nums(1e5, 0);

  for (auto &num: nums)
    num = rand() % static_cast<int>(2 * 1e4) - 1e4;

  Solution s;
  std::vector<int> counts1;
  std::vector<int> counts2;

  counts1.reserve(1e5);
  counts2.reserve(1e5);

  {
    auto start = chrono::steady_clock::now();
    counts1 = s.countSmaller(nums);
    auto end = chrono::steady_clock::now();

    printf("time cost of countSmaller using merge sort is %ld [ms]\n",
           chrono::duration_cast<chrono::milliseconds>(end - start).count());
  }

  {
    auto start = chrono::steady_clock::now();
    counts2 = s.count_smaller_binary_indexed_tree(nums);
    auto end = chrono::steady_clock::now();

    printf("time cost of countSmaller using binary indexed tree is %ld [ms]\n",
           chrono::duration_cast<chrono::milliseconds>(end - start).count());
  }

  ASSERT_EQ(counts1, counts2);
}


