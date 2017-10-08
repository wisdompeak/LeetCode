class Solution {
public:

    int minStickers(vector<string>& stickers, string target) 
    {        
        int n=target.size();
        int N=1<<n;
        vector<int>dp(N,-1);
        dp[0]=0;
        
        for (int i = 0; i < N; ++i)
        {            
            if(dp[i]==-1) continue;
            
            for (int k=0; k<stickers.size(); k++)
            {
                int now= i;
                
                for (int r=0; r<stickers[k].size(); r++)
                {
                    char ch = stickers[k][r];
                    
                    for (int s=0; s<n; s++)
                    {
                        if ((now>>s &1) ==0 && target[s]==ch)
                        {
                            now = now|1<<s;
                            break;
                        }
                    }
                }
                
                if (dp[now]==-1) 
                    dp[now]=dp[i]+1;
                else
                    dp[now]=min(dp[now],dp[i]+1);
            }
        }
        
        return dp[N-1];
    }
};
