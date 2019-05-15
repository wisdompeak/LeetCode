class Solution {
public:
    int minStickers(vector<string>& stickers, string target) 
    {
        int n = target.size();
        int N = (1<<n);
        vector<int>dp(N,INT_MAX);
        dp[0] = 0;

        for (int i=0; i<N; i++)
        {
            if (dp[i]==INT_MAX) continue;
            for (string str:stickers)
            {
                int j = findNextStatus(i,target,str);
                dp[j] = min(dp[j], dp[i]+1);
            }
        }
        return dp[N-1]==INT_MAX?-1: dp[N-1];
    }
    
    int findNextStatus(int status, string target, string s)
    {
        int n = target.size();
        for (auto ch:s)
        {
            for (int k=0; k<n; k++)
            {
                if (((status>>k)&1)==0 && target[k]==ch)
                {
                    status = status+(1<<k);   
                    break;
                }           
            }
        }
        return status;
    }
};
