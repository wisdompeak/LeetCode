using LL = long long;
class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) 
    {
        vector<int>odd;
        vector<int>even;
        for (int x: nums)
        {
            if (x%2==0) even.push_back(x);
            if (x%2==1) odd.push_back(x);
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());
        
        int m = odd.size();        
        vector<LL>prefix1(m+1);        
        for (int i=1; i<=m; i++)
            prefix1[i] = prefix1[i-1] + odd[i-1];
        
        int n = even.size();
        vector<LL>prefix2(n+1);        
        for (int i=1; i<=n; i++)
            prefix2[i] = prefix2[i-1] + even[i-1];
        
        LL ret = -1;
        int j = even.size();
        for (int i=0; i<=min(k, (int)odd.size()); i++)
        {
            while (i+j>k) j--;
            if (j<0) break;
            if (i+j==k && (prefix1[i]+prefix2[j])%2==0)
                ret = max(ret, prefix1[i]+prefix2[j]);            
        }
        
        return ret;
    }
};
