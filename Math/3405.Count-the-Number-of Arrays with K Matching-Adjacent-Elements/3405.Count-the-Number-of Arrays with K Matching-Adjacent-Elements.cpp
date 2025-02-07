using LL = long long;
class Solution {    
    LL MOD = 1e9 + 7;    
    LL comb[100005][75];  
public:
    int minMaxSums(vector<int>& nums, int k) 
    {
        int n = nums.size();
        for (int i = 0; i <= n; ++i) 
        {
            comb[i][0] = 1;            
            if (i==0) continue;
            for (int j = 1; j <= k; ++j) 
            {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                comb[i][j] %= MOD;
            }
        } 
                        
        sort(nums.begin(), nums.end());
        
        LL ret = 0;
        for (int i=0; i<n; i++)
        {
            for (int kk=0; kk<=min(i, k-1); kk++)
            {
                ret += comb[i][kk] * nums[i] % MOD;
                ret %= MOD;                
            }
            for (int kk=0; kk<=k-1; kk++)
            {
                ret += comb[n-1-i][kk] * nums[i] % MOD;
                ret %= MOD;
            }
        }
        return ret;        
    }
};
