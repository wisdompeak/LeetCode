class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if (k==0) return {};
        
        vector<int>results;
        
        multiset<int>Set;
        for (int i=0; i<k; i++)
            Set.insert(nums[i]);
        results.push_back(*Set.rbegin());
        
        for (int i=k; i<nums.size(); i++)
        {
            Set.insert(nums[i]);
            Set.erase(Set.lower_bound(nums[i-k]));
            results.push_back(*Set.rbegin());
        }
        
        return results;
    }
};
