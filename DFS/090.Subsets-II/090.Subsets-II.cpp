class Solution {
    vector<vector<int>>rets;    
    vector<int>visited;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int n = nums.size();
        visited.resize(n);

        rets.push_back({});
        sort(nums.begin(), nums.end());
        vector<int>temp;
        dfs(nums, 0, temp);
        return rets;
    }

    void dfs(vector<int>&nums, int cur, vector<int>&temp)
    {
        if (cur==nums.size())
            return;

        for (int i=cur; i<nums.size(); i++)
        {
            if ((i>=1 && nums[i]==nums[i-1]) && visited[i-1]==0)
                continue;

            visited[i] = 1;
            temp.push_back(nums[i]);            
            rets.push_back(temp);
            dfs(nums, i+1, temp);
            temp.pop_back();
            visited[i] = 0;
        }
    }
};
