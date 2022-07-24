using LL = long long;
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) 
    {
        vector<int>arr;
        unordered_set<int>Set(nums.begin(), nums.end());
        
        LL ret = 0;
        for (auto x: Set)
        {
            int count = __builtin_popcount(x);
            arr.push_back(count);        
            if (count * 2 >= k)
                ret++;
        }            
        
        sort(arr.begin(), arr.end());
               
        LL n = arr.size();
        LL j = n-1;        
        for (int i=0; i<n; i++)
        {
            while (j>=0 && arr[i]+arr[j]>=k)
                j--;
            if (j>=i)
                ret += (n-(j+1))*2;
            else
                ret += (n-(i+1))*2;
        }
        
        return ret;
    }
};
