class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) 
    {
        int sum=0;
        for (int i=0; i<A.size(); i++)
            sum+=A[i];
        int N=A.size();
        auto dp = vector<vector<bool>>(N+1,vector<bool>(sum+1,0));        
        dp[0][0]=1;
        
        for (int i=0; i<N; i++)
        {
            vector<pair<int,int>>temp;
            for (int Anum=0; Anum<=N; Anum++)
                for (int Asum=0; Asum<=sum; Asum++)
                {                    
                    if (dp[Anum][Asum]==1 && Anum+1<=N && Asum+A[i]<=sum)
                        temp.push_back({Anum+1,Asum+A[i]});
                }
            for (int j=0; j<temp.size(); j++)
                dp[temp[j].first][temp[j].second]=1;
        }
        
        for (int Anum=1; Anum<N; Anum++)
            for (int Asum=0; Asum<=sum; Asum++)
            {                    
                if (dp[Anum][Asum]==1 && Asum*1.0/Anum==(sum-Asum)*1.0/(N-Anum))
                   return true;                                                
            }
        
        return false;
    }
};
