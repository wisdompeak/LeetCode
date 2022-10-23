using LL = long long;
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) 
    {        
        vector<LL>odd1, odd2, even1, even2;
        for (auto x: nums)
        {
            if (x%2==0)
                even1.push_back(x);
            else
                odd1.push_back(x);
        }
        for (auto x: target)
        {
            if (x%2==0)
                even2.push_back(x);
            else
                odd2.push_back(x);
        }
        
        return helper(even1, even2) + helper(odd1, odd2);   
    }
    
    LL helper(vector<LL>&nums, vector<LL>&target)
    {
        sort(target.begin(), target.end());
        sort(nums.begin(), nums.end());
        
        LL count = 0;
        for (int i=0; i<nums.size(); i++)
            if (nums[i] > target[i])
                count += (nums[i]-target[i])/2;
        
        return count;
    }
    
};
