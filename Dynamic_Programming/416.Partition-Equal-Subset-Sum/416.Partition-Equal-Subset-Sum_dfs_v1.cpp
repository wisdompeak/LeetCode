class Solution {
    unordered_set<int>visited;
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        if (sum%2!=0) return false;
        return dfs(nums, 0, 0, sum/2);        
    }
    
    bool dfs(vector<int>& nums, int cur, int curSum, int targetSum)
    {
        int hash = curSum * 1000 + cur;
        if (visited.find(hash)!=visited.end()) 
            return false;
        
        if (curSum == targetSum) return true;
        if (curSum > targetSum) return false;
        if (cur==nums.size()) return false;
        
        for (int i=cur; i<nums.size(); i++)
        {
            if (i>cur && nums[i]==nums[i-1])
            {
                visited.insert((curSum+nums[i])*1000 + i);
                continue;
            }
            if (dfs(nums, i+1, curSum+nums[i], targetSum))
                return true;            
        }
        visited.insert(hash);
        return false;        
    }
};
