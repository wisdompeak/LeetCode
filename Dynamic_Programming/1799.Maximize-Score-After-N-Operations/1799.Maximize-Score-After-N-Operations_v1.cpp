class Solution {
    int dp[16384];
    int g[14][14];
public:
    int maxScore(vector<int>& nums) 
    {
        int n = nums.size()/2;
        for (int i=0; i<2*n; i++)
            for (int j=0; j<2*n; j++)
                g[i][j] = gcd(nums[i], nums[j]);
        
        for (int i=1; i<=n; i++)
        {
            int state = (1 << i*2) - 1;            
            while (state < (1 << n*2))
            {
                if (i==1)
                {
                    int x, y;
                    helper(state, x, y);                    
                    dp[state] = 1*g[x][y];                    
                }
                else
                {
                    for (int subset=state; subset>0; subset=(subset-1)&state)
                    {
                        if (__builtin_popcount(state-subset)!=2) continue;
                        int x, y;
                        helper(state-subset, x, y);
                        dp[state] = max(dp[state], dp[subset]+i*g[x][y]);
                    }                                
                }
                
                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }
        
        return dp[(1<<(2*n))-1];        
    }
    
    void helper(int state, int &x, int &y)
    {
        x = -1, y = -1;
        for (int i=0; i<14; i++)
        {
            if ((state>>i)&1)
            {
                if (x==-1)
                    x = i;
                else
                    y = i;
            }
        }
    }
};
