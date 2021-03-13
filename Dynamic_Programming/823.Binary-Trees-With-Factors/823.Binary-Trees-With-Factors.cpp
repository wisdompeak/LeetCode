class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) 
    {
        sort(A.begin(),A.end());
        
        int N=A.size();
        vector<long long>dp(N,1);
        long long M=pow(10,9)+7;
        unordered_map<int,long long>Map;
        
        for (int i=0; i<A.size(); i++)
            Map[A[i]]=i;
        
        for (int i=0; i<A.size(); i++)
        {
            for (int j=0; j<=i; j++)
            {                                
                if (A[i]%A[j]==0 && Map.find(A[i]/A[j])!=Map.end())
                {                    
                    int idx = Map[A[i]/A[j]];
                    dp[i]+=(dp[idx]*dp[j])%M;
                }
            }
            if (i>0 && A[0]==1)
                dp[i]+=2;
        }
        
        long long sum=0;
        for (int i=0; i<A.size(); i++)
            sum = (sum+dp[i])%M;
        
        return sum%M;
    }
};
