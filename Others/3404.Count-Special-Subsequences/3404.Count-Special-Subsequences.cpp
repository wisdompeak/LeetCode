using LL = long long;
class Solution {
public:
    LL getKey(int x, int y)
    {
        int g = gcd(x,y);
        x = x/g;
        y = y/g;
        return (LL)x*1000+y;
    }
    long long numberOfSubsequences(vector<int>& nums) 
    {
        unordered_map<LL, vector<int>>Map;
        int n = nums.size();
        for (int i=0; i<n; i++)
            for (int j=i+2; j<n; j++)            
                Map[getKey(nums[i], nums[j])].push_back(j);        
        
        for (auto& [k,v]:Map)
            sort(v.begin(), v.end());
        
        LL ret = 0;
        for (int r=2; r<n; r++)
            for (int s=r+2; s<n; s++)
            {
                int key = getKey(nums[s], nums[r]);                
                auto iter = lower_bound(Map[key].begin(), Map[key].end(), r-1);
                ret += iter - Map[key].begin();
            }
        return ret;
    }
};
