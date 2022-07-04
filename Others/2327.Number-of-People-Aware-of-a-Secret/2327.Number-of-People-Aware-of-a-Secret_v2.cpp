using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        vector<LL>diff(n+1);
        vector<LL>active(n+1);
        
        LL ret = 0;
        
        if (1+delay <= n)        
            diff[1+delay] += 1;
        if (1+forget <= n)        
            diff[1+forget] -= 1;
                
        for (int i=2; i<=n; i++)
        {
            active[i] = (active[i-1] + diff[i]) % M;
                        
            if (i+delay <= n)
                diff[i+delay] = (diff[i+delay] + active[i]) % M;
            if (i+forget <= n)
                diff[i+forget] = (diff[i+forget] - active[i] + M) % M;                         
        }
        
        for (int i=1; i<=n; i++)
            if (i+delay > n)
                ret = (ret + active[i]) % M;
        return (ret + active[n]) % M;        
    }
};
