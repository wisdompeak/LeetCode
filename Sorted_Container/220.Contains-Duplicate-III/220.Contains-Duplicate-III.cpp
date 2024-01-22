class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        multiset<long>Set;
        for (int i=0; i<nums.size(); i++)
        {
            if (i>k) Set.erase(Set.lower_bound((long)nums[i-k-1]));

            auto iter = Set.lower_bound((long)nums[i]-t);
            if (iter!=Set.end() && abs(*iter - (long)nums[i]) <= t) return true;

            Set.insert(nums[i]);
        }
        return false;
    }
};
