class Solution {
public:
    int countPalindromicSubsequences(string S) 
    {
        int N = S.size();
        auto dp = vector<vector<int>>(N,vector<int>(N,0));
        
        auto first = vector<vector<int>>(N,vector<int>(4,-1));
        auto last = vector<vector<int>>(N,vector<int>(4,-1));
        
        int MOD = 1e9+7;
        
        for (int len = 1; len<=N; len++)
            for (int i=0; i+len<=N; i++)
            {
                int j = i+len-1;
                
                if (first[i][S[j]-'a']==-1)
                    first[i][S[j]-'a'] = j;
                else
                    last[i][S[j]-'a'] = j;
                
                for (int k=0; k<4; k++)
                {
                    if (last[i][k]>=0)                    
                        dp[i][j]+=dp[first[i][k]+1][last[i][k]-1]+1;                    
                    if (first[i][k]>=0)
                        dp[i][j]+=1;                    
                    dp[i][j]%=MOD;
                }                
                
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        
        return dp[0][N-1];
        
    }
};
