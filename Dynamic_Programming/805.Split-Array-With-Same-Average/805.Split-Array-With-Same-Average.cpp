class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) 
    {
        int N = A.size();
        int SUM = accumulate(A.begin(),A.end(),0);
        double targetAvg = SUM*1.0/N;
        auto dp = vector<vector<bool>>(SUM/2+1,vector<bool>(N+1,false));
        A.insert(A.begin(),0);
        
        dp[0][0] = 1;        
            
        for (int i=1; i<=N; i++)
        {
            for (int sum = SUM/2; sum>=0; sum--)
                for (int num = i; num>=1; num--)
                {
                    if (sum-A[i]<0) continue;
                    if (dp[sum-A[i]][num-1])
                    {
                        dp[sum][num] = true;
                        if (num!=N && (sum *1.0/ num == targetAvg))
                            return true;
                    }
                }
        }
    
        return false;
        
    }
};
