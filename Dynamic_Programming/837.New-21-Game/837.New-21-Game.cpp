class Solution {
public:
    double new21Game(int N, int K, int W) 
    {
        vector<double>dp(N+W,1);       
        for (int i=N+1; i<N+W; i++)
            dp[i]=0;
        for (int i=K; i<=N; i++)
            dp[i]=1;       
        
        double temp = 0;        
        for (int k=K-1; k>=0; k--)
        {            
            if (k==K-1)
            {
                for (int i=1; i<=W; i++)
                    temp+=dp[k+i];
                dp[k]= temp*1.0/W;
            }            
            else if (k<K)
            {
                temp -= dp[k+W+1];
                temp += dp[k+1];
                dp[k]= temp*1.0/W;
            }            
        }
            
        return dp[0];
        
    }
    
};
