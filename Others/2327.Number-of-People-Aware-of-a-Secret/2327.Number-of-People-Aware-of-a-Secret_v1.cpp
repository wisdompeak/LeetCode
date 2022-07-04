using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {        
        vector<LL>active(n+1);
        
        active[1] = 1;
        
        LL ret = 0;
        for (int i=1; i<=n; i++)
        {
            for (int j=i+delay; j<i+forget; j++)
            {
                if (j>n) break;
                active[j] += active[i];                
                active[j] %= M;
            }            
        }
        
        for (int i=1; i<=n; i++)
            if (i+delay > n)
                ret = (ret + active[i]) % M;
        return (ret + active[n]) % M;
    }
};
