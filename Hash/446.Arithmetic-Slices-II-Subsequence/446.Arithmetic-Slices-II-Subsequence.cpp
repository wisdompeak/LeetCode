class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int N = A.size();
        auto dp = vector<unordered_map<long,int>>(N);
        int result = 0;
        
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<i; j++)
            {
                long diff = long(A[i])-long(A[j]);
                                
                dp[i][diff] += 1;
                
                if (dp[j].find(diff)!=dp[j].end())                
                {
                    dp[i][diff] += dp[j][diff];
                    result+=dp[j][diff];
                }
            }
        }
        return result;
    }
};
