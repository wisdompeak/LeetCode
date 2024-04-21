using LL = long long;
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>prevGreater(n, -1);
        
        stack<int>stk;
        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && nums[stk.top()]<=nums[i])
                stk.pop();
            if (!stk.empty()) prevGreater[i] = stk.top();
            stk.push(i);
        }
        
        unordered_map<int,vector<int>>Map;
        LL ret = 0;
        for (int i=0; i<n; i++)
        {
            Map[nums[i]].push_back(i);
            auto iter = upper_bound(Map[nums[i]].begin(), Map[nums[i]].end(), prevGreater[i]);                        
            ret += Map[nums[i]].end() - iter;
        }
        
        return ret;        
    }
};
