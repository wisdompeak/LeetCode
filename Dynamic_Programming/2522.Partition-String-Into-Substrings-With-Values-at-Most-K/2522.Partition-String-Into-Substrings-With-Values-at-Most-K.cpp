class Solution {
    int dp[100005];
public:
    int minimumPartition(string s, int k) 
    {
        int n = s.size();
        int m = to_string(k).size();
        for (int i=0; i<n; i++)
        {
            if (m==1 && s[i]-'0'>k)
                return -1;
        }
        
        s = "#"+s;        
        dp[0] = 0;
        
        for (int i=1; i<=n; i++)
        {            
            if (i-m+1>=1 && stoi(s.substr(i-m+1, m)) <= k)
                dp[i] = dp[i-m] + 1;
            else 
                dp[i] = dp[max(0, i-m+1)] + 1;
        }
        
        return dp[n];
        
    }
};
