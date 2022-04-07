using ll = long long;
class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {        
        ll comb[1000][1000];  
        int n = nums.size()-1;
        for (int i = 0; i <= n; ++i) 
        {
            comb[i][i] = comb[i][0] = 1;            
            if (i==0) continue;
            for (int j = 1; j < i; ++j) 
            {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                comb[i][j] %= 10;
            }
        }  

        ll ret = 0;
        for (int i=0; i<=n; i++)
        {
            ret += nums[i]*comb[n][i]%10;
        }
            
        return ret%10;
    }
};
