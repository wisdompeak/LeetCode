class Solution {
public:
  std::vector<int> countSmaller(std::vector<int> &nums)
  {
    // when iterating to index i, we want to efficiently
    // know how many elements on the right are less than nums[i]

    // it may be impossible to get to know this information in O(1)
    // therefore, O(logn) is the best achievement.

    // considering O(logn), there are two data structure candidates

    // binary indexed tree and segment tree

    // since, we only want to count element of which value < nums[i]
    // instead of ? < value < nums[i]

    // binary indexed tree is the choice.

    if (nums.empty())
      return std::vector<int>();

    auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());

    // mapping *min_it to be 1
    int delta = 1 - *min_it;

    int min = *min_it + delta;
    int max = *max_it + delta;

    // There are 2107 trees on the dota 2 map.
    binary_indexed_tree tree(max);

    std::vector<int> counts(nums.size(), 0);

    for (int i = nums.size()-1; i >= 0; --i)
    {
      // query how many elements are less than nums[i]
      int num = nums[i] + delta;
      counts[i] = tree.query(num-1);

      tree.update(num, 1);
    }

    return counts;
  }

private:
  struct binary_indexed_tree
  {
    std::vector<int> _arr;

    binary_indexed_tree(int max_val)
    : _arr(max_val+1, 0)
    {
      // for binary indexed tree, index 0 means nothing,
      // therefore, if we want to store the information of max_val
      // we need an array of which the length is equal to max_val+1
    }

    /** @brief query prefix sum of range [0, i] of internal array
     *  @param: i  int   inclusive end pos of prefix sum array
     *  @return: prefix sum value
     **/
    int query(int i)
    {
      assert (i < _arr.size());

      int ret = 0;

      for (auto j = i; j > 0; j -= lowbit(j))
        ret += _arr[j];

      return ret;
    }

    void update(int i, int val)
    {
      assert (i > 0); // logical error to touch array[i]
      assert (i < _arr.size());

      for (auto j = i; j < _arr.size(); j += lowbit(j))
        _arr[j] += val;
    }

    int lowbit(int i) { return i & (-i); }
  };
};
