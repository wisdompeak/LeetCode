class Solution {
    int dp[1<<12];
    unordered_map<int,int>memo;
public:
    bool isPalin(string&s, int state)
    {
        if (memo.find(state)!=memo.end())
            return memo[state];
        
        vector<int>idx;
        int n = s.size();
        for (int i=0; i<n; i++)
        {
            if ((state>>i)&1)
                idx.push_back(n-1-i);
        }
        reverse(idx.begin(), idx.end());
        
        int i=0, j=idx.size()-1;
        while (i<j)
        {
            if (s[idx[i]]!=s[idx[j]])
            {
                memo[state]=0;
                return false;
            }                
            i++;
            j--;
        }
        memo[state]=1;
        return true;
    }
    
    
    int maxProduct(string s) 
    {
        int n = s.size();
        
        for (int state=1; state<(1<<n); state++)
        {
            int t = __builtin_popcount(state);
            if (isPalin(s, state))
            {
                dp[state] = t;
                continue;
            }
            for (int i=0; i<n; i++)
            {
                if ((state>>i)&1)                
                    dp[state] = max(dp[state], dp[state-(1<<i)]);                
            }
        }        
        
        int all = (1<<n)-1;
        int ret = 0;
        for (int subset=1; subset<(1<<n); subset++)
            ret = max(ret, dp[all-subset]*dp[subset]);
        return ret;        
    }
};
