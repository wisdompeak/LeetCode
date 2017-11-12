class Solution {
public:
    string minWindow(string S, string T) 
    {
        int M=S.size();
        int N=T.size();
        S.insert(S.begin(),'0');
        T.insert(T.begin(),'0');
        int inf=100000;
        auto dp=vector<vector<int>>(N+1,vector<int>(M+1,inf));
        
        for (int j=0; j<=M; j++)
            dp[0][j]=0;
        
        for (int i=1; i<=N; i++)
         for (int j=1; j<=M; j++)
         {
             if (T[i]==S[j])
                 dp[i][j]=dp[i-1][j-1]+1;
             else
                 dp[i][j]=dp[i][j-1]+1;
         }
        
        int len_min=INT_MAX;
        for (int j=1; j<=M; j++)
            len_min=min(len_min,dp[N][j]);
        
        if (len_min>=inf) return "";
        
        int k;
        for (int j=1; j<=M; j++)
        {
            if (len_min==dp[N][j])
            {
                k=j;
                break;
            }
        }
        
        //cout<<k<<endl;
        //cout<<len_min<<endl;
        return S.substr(k-len_min+1,len_min);
    }
};
