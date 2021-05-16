typedef long long ll;
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) 
    {
        int MaxN = 100000;
        vector<int>count(MaxN+1);        
        for (auto x: nums)
            count[x]++;
        
        vector<int>presum(MaxN+1);        
        for (int i=1; i<=MaxN; i++)
            presum[i] = presum[i-1]+count[i];
        
        vector<int>visited(MaxN+1,0);
                
        ll ret = 0;
        ll M = 1e9+7;
        for (auto x: nums)
        {
            if (visited[x]==1) continue;                        
            ll ans = 0;
            
            int k;  // [k*x, (k+1)*x-1]
            for (k=1; x*k+x-1<=MaxN; k++)
            {
                ans = ans + (presum[x*k+x-1]-presum[x*k-1])*k%M;
                ans %= M;
            }
            
            if (x*k+x-1>MaxN && x*k-1<=MaxN)
            {                
                ans = ans + (presum[MaxN] - presum[x*k-1]) * k % M;
                ans %= M;
            }
                        
            ret = (ret + ans * count[x]) % M;  

            visited[x] = 1;          
        }
        
        return ret;
    }
};
