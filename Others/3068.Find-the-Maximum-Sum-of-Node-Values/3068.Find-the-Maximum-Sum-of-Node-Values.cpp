using LL = long long;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {        
        vector<pair<int,int>>diff;
        for (int x: nums)
        {
            diff.push_back({(x^k)-x, x});
        }
        
        sort(diff.rbegin(), diff.rend());
        
        LL max_diff = 0;
        LL total_diff = 0;
        for (int i=0; i+1<diff.size(); i+=2)
        {
            total_diff += diff[i].first;
            total_diff += diff[i+1].first;
            if (total_diff > max_diff)
            {
                max_diff = total_diff;                
            }
        }
        
        LL total = 0;
        for (int x: nums) total += x;
        
        return total + max_diff;
        
    }
};
