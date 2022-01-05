class Solution {
public:
  int longestArithSeqLength(vector<int>& nums)
  {
    // dynamic algorithm to solve longest arith sequence length
    // dp[i][diff] = dp[j][diff] + 1 if diff exist in dp[j]
    //                               else 2
    //    where j < i
    // and, it is guaranteed that if diff exists in both j and k where j < k
    // dp[j][diff] <= dp[k][diff]

    int n = nums.size();

    static int lASL_MAX = 1000;
    static int lASL_MIN = 2;

    // the maximum diff to form a longer arith sequence by looking forward
    static int DIFF = (lASL_MAX-lASL_MIN)/2;

    // biggest size the diff array should be maintained
    static int DIFF_MAX_SIZE = 2 * DIFF + 1;

    // the 2d dp array, row label is array index, column label is diff + DIFF

    // if one num is not formed an arith sequence, we think it has potential
    // to form any arith sequence
    std::vector<std::vector<int>> dp(n, std::vector<int>(DIFF_MAX_SIZE, 1));

    int lasl = 2;

    for (auto r = 0; r != n; ++r)
    {
      for (auto l = 0; l < r; ++l)
      {
        int diff = nums[r] - nums[l];
        if (diff > DIFF || diff < -DIFF)
          continue;

        diff += DIFF;

        dp[r][diff] = dp[l][diff] + 1;

        lasl = std::max(lasl, dp[r][diff]);
      }
    }

    return lasl;
  }
};
