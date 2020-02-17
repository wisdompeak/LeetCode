class Solution {
    map<vector<int>,int>Map;
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==0) return 0;
        return max(nums[0]+DFS(2,n-2,nums), DFS(1,n-1,nums));
    }
    
    int DFS(int i, int j, vector<int>&nums)
    {
        if (i>j) return 0;
        
        if (i==j) return nums[i];
        
        if (Map.find({i,j})!=Map.end())
            return Map[{i,j}];
        
        int ret = max(nums[i]+DFS(i+2,j,nums), DFS(i+1,j,nums));
        
        Map[{i,j}] = ret;
        
        return ret;
    }
};
