using LL = long long;
class Solution {
    LL power[100005];
    LL fact[100005];
    LL mod = 1e9+7;
public:
    int numberOfSequence(int n, vector<int>& sick) 
    {
        power[0] = 1;
        for (int i=1; i<=n; i++)
            power[i] = power[i-1]*2 % mod;
        
        fact[0] = 1;
        for (int i=1; i<=n; i++)
            fact[i] = fact[i-1]*i % mod;
        
        vector<int>groups;
        for (int i=0; i<sick.size(); i++)
        {
            if (i==0)
                groups.push_back(sick[i]);
            else 
                groups.push_back(sick[i]-sick[i-1]-1);                                
        }
        groups.push_back(n-1-sick.back());
        
        int total = accumulate(groups.begin(), groups.end(), 0);
        
        LL ret = fact[total];
        for (int x: groups) 
            ret = ret * inv(fact[x]) % mod;
                
        for (int i=1; i<sick.size(); i++)
        {
            int x = sick[i]-sick[i-1]-1;
            if (x>0)
                ret = ret * power[x-1] % mod;
        }
        
        return ret;
    }
    
    LL quickPow(LL x, LL y) 
    {
        LL ret = 1;
        LL cur = x;
        while (y) 
        {
            if (y & 1) 
            {
                ret = (LL)ret * cur % mod;
            }
            cur = (LL)cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }

    LL inv(LL x) 
    {
        return quickPow(x, mod - 2);
    }
};
