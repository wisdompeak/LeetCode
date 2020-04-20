class Solution {
    vector<int>temp1, temp2;
public:
    int numOfWays(int n) 
    {
        vector<int>dp(27,0);
        int M = 1e9+7;
        temp1.resize(3);
        temp2.resize(3);
        
        for (int p=0; p<27; p++)
        {
            if (selfOK(p))
                dp[p] = 1;
        }

        for (int i=1; i<n; i++)
        {
            auto dp_prev = dp;
            for (int p=0; p<27; p++)
            {
                dp[p] = 0;
                if (!selfOK(p)) continue;
                for (int q=0; q<27; q++)
                {
                    if (!selfOK(q)) continue;
                    if (crossOK(p,q))
                        dp[p] = (dp[p]+dp_prev[q])%M;
                }
            }
        }
        
        int sum = 0;
        for (int p=0; p<27; p++)
        {
            if (selfOK(p))
                sum = (sum+dp[p])%M;
        }
        return sum;
        
    }
    
    bool selfOK(int p)
    {
        for (int i=0; i<3; i++)
        {
            temp1[i] = (p%3);
            p/=3;
        }
        return (temp1[0]!=temp1[1] && temp1[1]!=temp1[2]);
    }
    
    bool crossOK(int p, int q)
    {
        
        for (int i=0; i<3; i++)
        {
            temp1[i] = (p%3);
            temp2[i] = (q%3);
            p/=3;
            q/=3;
        }
        return (temp1[0]!=temp2[0] && temp1[1]!=temp2[1] && temp1[2]!=temp2[2]);
    }
    
};
