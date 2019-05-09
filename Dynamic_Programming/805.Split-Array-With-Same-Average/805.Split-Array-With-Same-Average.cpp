class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) 
    {
        int sum=0;
        for (int i=0; i<A.size(); i++)
            sum+=A[i];
        int N=A.size();
        A.insert(A.begin(),0);
        auto dp = vector<vector<bool>>(N+1,vector<bool>(sum/2+1,0));        
        dp[0][0]=1;
        
        
        for (int i=1; i<=N; i++)
        {
            auto temp = dp;
            
            for (int Asum=0; Asum<=sum/2; Asum++)
                for (int Anum=1; Anum<=i; Anum++)
                {                    
                    if (Anum-1>=0 && Asum-A[i]>=0 && temp[Anum-1][Asum-A[i]])
                    {
                        dp[Anum][Asum]=1;
                        if (Anum!=N && (Asum*1.0/Anum==sum*1.0/N))                        
                            return true;                        
                    }                    
                }            
        }
        
        return false;
    }
};
