class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) 
    {
        int n=A.size();
        vector<int>dp(N,INT_MAX/2);
        vector<int>path(n,-1);
        dp[n-1]=A[n-1];
        
        for (int i=n-1; i>=0; i--)
        {
            for (int k=1; k<=B; k++)
            {
                if (i+k>=A.size())
                    continue;
                if (A[i+k]==-1)
                    continue;
                
                if (dp[i+k]+A[i]<dp[i])
                {
                    dp[i]=dp[i+k]+A[i];
                    path[i]=i+k;
                }
            }
        }
        
        vector<int>result;
        int i=0;
        while (i<A.size())
        {
            result.push_back(i+1);   
            
            if (i==A.size()-1)
                break;
            
            if (path[i]==-1) 
                return {};
            else
                i=path[i];  
        }
                
        return result;
    }
};
