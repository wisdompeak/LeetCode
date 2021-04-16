class Solution {
    vector<int> stateSet[8];
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
                stateSet[i].push_back(state);
                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }
        stateSet[0].push_back(0);
        
        
        for (int i=1; i<=n; i++)
        {
            for (int state: stateSet[i])
                for (int subState: stateSet[i-1])
                {
                    if ((state&subState)!=subState)
                        continue;
                    int x, y;
                    helper(state-subState, x, y);
                    dp[state] = max(dp[state], dp[subState]+i*g[x][y]);
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
