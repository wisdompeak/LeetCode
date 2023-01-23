class Solution {
    int dp[1005];
public:
    int minCost(vector<int>& nums, int k) 
    {
        int n = nums.size();        

        for (int i=0; i<n; i++)
        {
            unordered_map<int,int>Map;
            int score = 0;
            dp[i] = INT_MAX;
            for (int j=i; j>=0; j--)
            {
                Map[nums[j]]++;
                if (Map[nums[j]]==2)
                    score += 2;
                else if (Map[nums[j]]>2)
                    score += 1;

                if (j>=1)
                    dp[i] = min(dp[i], dp[j-1] + score + k);
                else
                    dp[i] = min(dp[i], score + k);
            }
        }
        return dp[n-1];
    }
};
