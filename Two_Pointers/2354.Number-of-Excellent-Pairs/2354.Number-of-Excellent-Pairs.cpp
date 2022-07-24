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
            arr.push_back(__builtin_popcount(x));        
        }            
        
        sort(arr.begin(), arr.end());
               
        LL n = arr.size();
        LL j = n-1;        
        for (int i=0; i<n; i++)
        {
            while (j>=0 && arr[i]+arr[j]>=k)
                j--;
            if (j>=i)
                ret += n-(j+1);
            else
                ret += n-(i+1);
        }
        ret *= 2;
        
        for (auto x: arr)
        {
            if (x*2>=k)
                ret++;
        }
        
        return ret;
    }
};
