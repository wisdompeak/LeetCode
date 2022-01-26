class Solution {    
public:
    vector<int> countSmaller(vector<int>& nums) 
    {        
        int N = nums.size();
        if (N==0) return {};
        
        vector<int>sortedNums = nums;        
        vector<int>counts(N,0);
        DivideConque(nums,sortedNums, counts, 0, nums.size()-1);  // 0表示起点，N-1表示终点
        return counts;
    }
    
    void DivideConque(vector<int>&nums, vector<int>&sortedNums, vector<int>&counts, int start, int end)
    {
        if (start==end) return;
        
        // 如果需要处理的元素有多个，则折半分治处理。注意：分治处理后的sortedNums前后两部分元素都是有序的。
        int mid = start+(end-start)/2;
        DivideConque(nums, sortedNums, counts, start,mid);
        DivideConque(nums, sortedNums, counts, mid+1, end);
        
        // OK，既然现在start~mid和mid+1~end这两段都分别有序，
        // 那么对于start~mid中的任何一个元素，我们都可以轻易地知道在mid+1~end中有多少小于它的数
        for (int i=start; i<=mid; i++)
        {
            int val = nums[i];
            auto pos = lower_bound(sortedNums.begin()+mid+1, sortedNums.begin()+end+1,val);            
            counts[i] += pos-(sortedNums.begin()+mid+1);
        }
        
        // 将两段已经有序的数组段start~mid,mid+1~end合起来排序。
        // 如果写归并排序的code会更快一些。这里就偷懒了，直接用sort函数。        
        sort(sortedNums.begin()+start,sortedNums.begin()+end+1);        
    }

  std::vector<int> count_smaller_binary_indexed_tree(std::vector<int> &nums)
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
