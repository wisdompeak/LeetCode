using LL = long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int n = nums.size()/3;        
        
        multiset<LL>Set;        
        LL sum = 0;
        
        for (int i=0; i<n; i++)
        {
            Set.insert(nums[i]);
            sum += nums[i];
        }            
        vector<LL>left(3*n);
        left[n-1] = sum;        
        for (int i=n; i<2*n; i++)
        {
            Set.insert(nums[i]);
            sum += nums[i];
            sum -= *(Set.rbegin());
            left[i] = sum;
            int t = *(Set.rbegin());
            Set.erase(Set.lower_bound(t));
        }
        for (int i=n; i<2*n; i++)
            left[i] = min(left[i], left[i-1]);
        
        
        Set.clear();
        sum = 0;        
        for (int i=3*n-1; i>=2*n; i--)
        {
            Set.insert(nums[i]);
            sum += nums[i];
        }            
        vector<LL>right(3*n);
        right[2*n] = sum;        
        for (int i=2*n-1; i>=n; i--)
        {
            Set.insert(nums[i]);
            sum += nums[i];
            sum -= *(Set.begin());
            right[i] = sum;
            Set.erase(Set.begin());
        }
        for (int i=2*n-1; i>=0; i--)
            right[i] = max(right[i], right[i+1]);
        
        LL ret = LLONG_MAX;
        for (int i=n-1; i<2*n; i++)
            ret = min(ret, left[i]-right[i+1]);
        return ret;
    }
};
