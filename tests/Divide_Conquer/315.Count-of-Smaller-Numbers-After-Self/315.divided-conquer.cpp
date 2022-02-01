#include <315.divided-conquer.h>
#include <Divide_Conquer/315.Count-of-Smaller-Numbers-After-Self/315.Count-of-Smaller-Numbers-After-Self.cpp>

#include <stdio.h>

std::vector<int> count_v1(std::vector<int> &nums)
{
  static Solution s;
  return s.countSmaller(nums);
}