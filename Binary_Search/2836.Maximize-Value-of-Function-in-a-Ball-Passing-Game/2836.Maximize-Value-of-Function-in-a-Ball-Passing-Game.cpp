using LL = long long;
class Solution {
    LL dp[100005][35];
    int pos[100005][35];
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) 
    {
        int n = receiver.size();
        int M = ceil(log(k)/log(2));

        for (int i=0; i<n; i++)
        {
            pos[i][0] = receiver[i];
            dp[i][0] = receiver[i];
        }

        for (int j=1; j<=M; j++)
            for (int i=0; i<n; i++)
            {
                pos[i][j] = pos[pos[i][j-1]][j-1];
                dp[i][j] = dp[i][j-1] + dp[pos[i][j-1]][j-1];
            }

        vector<int>bits;
        for (int i=0; i<=M; i++)
        {
            if ((k>>i)&1)
                bits.push_back(i);
        }

        LL ret = 0;
        for (int i=0; i<n; i++)
        {
            LL val = i;
            int cur = i;
            for (int j: bits)
            {
                val += dp[cur][j];
                cur = pos[cur][j];
            }
            ret = max(ret, val);
        }

        return ret;
    }
};
