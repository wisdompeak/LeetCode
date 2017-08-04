class Solution {    
public:
    int numDistinct(string s, string t) 
    {
        int M=s.size();
        int N=t.size();
        if (M==0||N==0) return 0;
        
        auto dp=vector<vector<int>>(M,vector<int>(N,0));
                
        int count=0;
        for (int i=0; i<M; i++)
        {
            if (s[i]==t[0])            
                count++;
            dp[i][0]=count;                            
        }
        
                
        for (int j=1; j<N; j++)
         for (int i=j; i<M; i++)
         {             
             if (s[i]==t[j])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
             else
                dp[i][j]=dp[i-1][j];                  
         }
              
        return dp[M-1][N-1];
    }
};
