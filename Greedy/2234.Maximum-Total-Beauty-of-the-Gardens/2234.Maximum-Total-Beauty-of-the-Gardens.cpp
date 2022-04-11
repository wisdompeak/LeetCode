using LL = long long;
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) 
    {
        sort(flowers.begin(), flowers.end());
        
        LL ret0 = 0;
        while (flowers.size()>0 && flowers.back()>=target)
        {
            ret0 += full;
            flowers.pop_back();
        }        
        if (flowers.empty()) return ret0;
        
        LL n = flowers.size();                
        vector<LL>presum(n);
        for (LL i=0; i<n; i++)
            presum[i] = (i==0?0:presum[i-1])+flowers[i];
        vector<LL>diff(n);
        for (LL i=0; i<n; i++)
            diff[i] = (i+1)*flowers[i] - presum[i];        
                
        LL ret = 0;        
        for (int i=n-1; i>=0; i--)
        {
            if (newFlowers < 0) break;
            
            if (presum[i]+newFlowers >= (LL)(target-1)*(i+1))
            {
                ret = max(ret, (LL)(target-1)*partial + (LL)(n-1-i)*full);                
            }
            else
            {
                auto iter = upper_bound(diff.begin(), diff.begin()+i+1, newFlowers);
                int k = prev(iter) - diff.begin();
                LL total = presum[k] + newFlowers;
                LL each = total / (LL)(k+1);
                ret = max(ret, each*partial + (LL)(n-1-i)*full);                                      
            }
            newFlowers -= target-flowers[i];             
        }
        
        if (newFlowers>=0)
            ret = max(ret, n*full);
        
        return ret + ret0;
    }
};
