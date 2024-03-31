using LL = long long;
class Solution {
    LL M = 1e9+7;
    int n;
public:
    int sumOfPowers(vector<int>& nums, int K) 
    {
        n = nums.size();
        sort(nums.begin(), nums.end());        
        nums.insert(nums.begin(), 0);

        LL ret = 0;
        for (int i=1; i<=n; i++)
            for (int j=i+1; j<=n; j++)
            {
                int d = nums[j]-nums[i];
                ret = (ret + helper(nums, K, d, i, j)) % M;
            }
        return ret;        
    }

    LL helper(vector<int>& nums, int K, int d, int a, int b)
    {
        vector<vector<LL>>dp1(n+2, vector<LL>(n+2));
        vector<vector<LL>>dp2(n+2, vector<LL>(n+2));

        for (int i=1; i<=n; i++)
        {
            dp1[i][1] = 1;
            dp2[i][1] = 1;
        }
        
        for (int i=1; i<=a; i++)
            for (int j=2; j<=K; j++)
            {
                for (int k=1; nums[i]-nums[k]>d && k<i; k++)
                    dp1[i][j] = (dp1[i][j] + dp1[k][j-1]) % M;
            }

        for (int i=n; i>=b; i--)
            for (int j=2; j<=K; j++)
            {
                for (int k=n; nums[k]-nums[i]>=d && k>i; k--)
                    dp2[i][j] = (dp2[i][j] + dp2[k][j-1]) % M;
            }

        LL ret = 0;
        for (int t=1; t<K; t++)
        {
            ret += dp1[a][t] * dp2[b][K-t] % M;
            ret %= M;
        }
        return ret * d ;
    }
};
