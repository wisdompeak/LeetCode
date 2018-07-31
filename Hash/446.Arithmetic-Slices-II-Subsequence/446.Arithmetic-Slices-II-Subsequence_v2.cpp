class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<A.size(); i++)
            Map[A[i]].push_back(i);
        
        int N = A.size();
        auto dp = vector<vector<int>>(N,vector<int>(N,0));
        for (int i=0; i<N; i++)
            for (int j=0; j<i; j++)
            {
                long m = A[j]*2L-A[i];
                if (m>INT_MAX || m<INT_MIN) continue;
                for (int k:Map[m])
                {
                    if (k<j)
                        dp[j][i] += dp[k][j]+1;
                }
            }
        int count = 0;
        for (int j=0; j<N; j++)
            for (int i=j+1; i<N; i++)
                count+=dp[j][i];
        return count;
    }
};
