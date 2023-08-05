class Solution {
public:
    int minimumSeconds(vector<int>& nums) 
    {
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<nums.size(); i++)
        {
            Map[nums[i]].push_back(i);
        }
        
        int ret = INT_MAX;
        for (auto& [k,arr]: Map)
        {
            int n = nums.size();
            arr.push_back(n+arr[0]);
            int ans = 0;
            for (int i=0; i<arr.size()-1; i++)
                ans = max(ans, (arr[i+1]-arr[i])/2);
            ret = min(ret, ans);                
        }
        return ret;
        
    }
};
