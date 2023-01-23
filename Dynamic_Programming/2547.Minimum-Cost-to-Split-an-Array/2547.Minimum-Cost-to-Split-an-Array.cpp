using LL = long long;
class Solution {
    LL dp[1005];
public:
    int minCost(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int,int>Map;
        for (int i=0; i<n; i++)
        {
            dp[i] = LLONG_MAX;
            Map.clear();            
            LL v = 0;
            for (int j=i; j>=0; j--)
            {
                Map[nums[j]]++;
                if (Map[nums[j]]==2)
                    v+=2;
                else if (Map[nums[j]]>2)
                    v+=1;                
                
                if (j>=1)
                    dp[i] = min(dp[i], dp[j-1] + v+k);
                else
                    dp[i] = min(dp[i], v+k);
            }            
        }
        return dp[n-1];
        
    }
};
