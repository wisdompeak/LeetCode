using LL = long long;
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        int n = nums.size();
        vector<pair<LL,LL>>arr;        
        for (int i=0; i<n; i++)
        {
            arr.push_back({nums[i], cost[i]});
        }
        sort(arr.begin(), arr.end());
        
        LL totalCost = accumulate(cost.begin(), cost.end(), 0LL);
        LL curCost = 0;
        int k;
        for (int i=0; i<arr.size(); i++)
        {
            curCost += arr[i].second;
            if (curCost >= totalCost*1.0/2)
            {
                k = i;
                break;
            }
        }
            
        LL ret = 0;
        for (int i=0; i<arr.size(); i++)
        {
            ret += abs(arr[i].first-arr[k].first)*arr[i].second;            
        }        
        return ret;
    }
};
