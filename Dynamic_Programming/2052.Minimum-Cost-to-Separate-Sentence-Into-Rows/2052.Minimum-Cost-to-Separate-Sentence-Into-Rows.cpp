class Solution {
public:
    int minimumCost(string sentence, int k) 
    {
        vector<int>nums;
        for (int i=0; i<sentence.size(); i++)
        {
            int j = i;
            while (j<sentence.size() && isalpha(sentence[j]))
                j++;
            nums.push_back(j-i);
            i = j;
        }
        
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        
        int ret = INT_MAX/2;
        vector<int>dp(n+1, INT_MAX/2);
        dp[0] = 0;
        for (int i=1; i<=n; i++)
        {
            int len = -1;
            int j = i;
            while (j>=1 && len+nums[j]+1 <= k)
            {
                len += nums[j]+1;                
                dp[i] = min(dp[i], dp[j-1]+(k-len)*(k-len));
                                                
                if (i==n) ret = min(ret, dp[j-1]);
                j--;
            }               
        }
        
        return ret;        
    }
};
