class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int n = A.size();
        unordered_map<long,int>dp[1000];
        int count = 0;
        
        for (int i=1; i<A.size(); i++)
        {
            for (int j=i-1; j>=0; j--)
            {
                long diff = (long)A[i]-(long)A[j];
                count += dp[j][diff];
                
                if (dp[j].find(diff)!=dp[j].end())
                    dp[i][diff] += dp[j][diff]+1;                                    
                else
                    dp[i][diff] = 1;
            }
        }
                    
        return count;
    }
};
