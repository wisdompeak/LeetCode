/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    vector<int> preprocess(vector<int> s)
    {
        int n = s.size();
        vector<int>dp(n,0);
        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];                       
            while (j>=1 && s[j]!=s[i])
            {
                j = dp[j-1];
            }          
            dp[i] = j + (s[j]==s[i]);
        }
        return dp;
    }

    int findPattern(InfiniteStream* stream, vector<int>& pattern) 
    {
        int m = pattern.size();
        if (m==0) return 0;

        vector<int> suf = preprocess(pattern);
        
        unordered_map<int,int>dp;
        
        int num = stream->next();
        dp[0] = (num==pattern[0]);
        if (m==1 && dp[0]==1)
            return 0;

        int i = 1;
        while (1)
        {
            int num = stream->next();

            int j = dp[i-1];
            while (j>0 && (j==pattern.size() || num!=pattern[j]))
                j = suf[j-1];
            dp[i] = j + (num==pattern[j]);
            if (dp[i]==m)
                return i-pattern.size()+1;
            i++;
        }
        return -1;
    }
};
