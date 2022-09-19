using LL = long long;
class Solution {
public:
    long long maximumBooks(vector<int>& books) 
    {
        int n = books.size();
        vector<LL>dp(n);
        stack<LL>stk;
        
        LL ret = 0;
        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && books[stk.top()] > books[i]-(i-stk.top()))            
                stk.pop();
            
            if (!stk.empty())
            {
                LL d = i - stk.top();
                dp[i] = dp[stk.top()] + ((LL)books[i] + (LL)books[i] - d + 1) * d /2;                
            }
            else
            {
                LL d = min(i + 1, books[i]);
                dp[i] = ((LL)books[i] + (LL)books[i] - d + 1) * d /2;                
            }
            stk.push(i);
            
            ret = max(ret, dp[i]);
        }
        
        return ret;        
    }
};
