class Solution {
    unordered_set<int>visited;
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2!=0) return false;
        return dfs(nums, sum/2, 0, 0);        
    }
    
    bool dfs(vector<int>& nums, int targetSum, int i, int sum)
    {
        int hash = sum * 1000 + i;
        if (visited.find(hash)!=visited.end())
            return false;
        
        if (sum== targetSum)
            return true;
        
        if (sum> targetSum)
            return false;
        
        if (i == nums.size())
            return false;
        
        if (dfs(nums, targetSum, i + 1, sum+ nums[i]) || dfs(nums, targetSum, i + 1, sum))
            return true;
        
        visited.insert(hash);
        return false;        
    }
};
