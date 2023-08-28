using LL = long long;
class Solution {
    int pos[100005][35];
    LL dp[100005][35];
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) 
    {
        int n = receiver.size();
        int M = 0;
        LL K = k;
        while (K>0)
        {
            M++;
            K/=2;
        }

        for (int i=0; i<n; i++)
        {
            pos[i][0] = receiver[i];
            dp[i][0] = receiver[i];
        }

        
        for (int k=1; k<M; k++)
        {
            for (int i=0; i<n; i++)
            {
                pos[i][k] = pos[pos[i][k-1]][k-1];
                dp[i][k] = dp[i][k-1] + dp[pos[i][k-1]][k-1];
            }
        }

        vector<int>bits;
        for (int i=0; i<M; i++)
        {
            if ((k>>i)&1)
                bits.push_back(i);
        }
        
        LL ret = 0;
        for (int i=0; i<n; i++)
        {
            LL ans = i;
            int cur = i;
            for (int j: bits)
            {
                ans += dp[cur][j];
                cur = pos[cur][j];
            }
            ret = max(ret, ans);                
        }

        return ret;
    }
};
