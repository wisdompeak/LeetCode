class Solution {
public:
    double new21Game(int N, int K, int W) 
    {
        vector<double>dp(N+1,0);
        dp[0] = 1;
        double sum = 0;
        
        for (int i=1; i<=N; i++)
        {
            if (i-1<K)
                sum += dp[i-1];
            if (i-W-1>=0)
                sum -= dp[i-W-1];
            
            dp[i] = sum*1/W;
        }
        
        double result = 0;
        for (int i=K; i<=N; i++)
            result += dp[i];
        
        return result;
    }
    
    
    //LTE solution: DFS(0,N,K,W)
    double DFS(int cur, int N, int K, int W)
    {
        if (cur>=K)
        {
            if (cur<=N)
                return 1;
            else
                return 0;
        }
        
        double sum = 0;
        for (int i=1; i<=W; i++)
        {
            sum += 1.0/W * DFS(cur+i,N,K,W);
        }
        return sum;
    }
};
