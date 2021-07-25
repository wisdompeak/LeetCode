class Solution {
    int m, n, t;
    int match[8][8];

public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) 
    {
        m = students.size();
        n = students[0].size();        
        
        for (int i=0; i<m; i++)
            for (int j=0; j<m; j++)
            {
                int count = 0;
                for (int k=0; k<n; k++)
                    count += (students[i][k]==mentors[j][k]);
                match[i][j] = count;
            }
        
        
        vector<int>dp(1<<m);
        
        for (int k=0; k<m; k++)
        {
            int state = (1 << (k+1)) - 1;            
            while (state < (1 << m))
            {
                for (int i=0; i<m; i++)
                {                    
                    if (((state>>i)&1)==0)
                        continue;
                    dp[state] = max(dp[state], dp[state - (1<<i)] + match[i][k]);
                }

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }
        
        return dp[(1<<m)-1];
    }
};
