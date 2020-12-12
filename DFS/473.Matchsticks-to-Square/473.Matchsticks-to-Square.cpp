class Solution {
    bool visited[15];
    int total;
public:
    bool makesquare(vector<int>& nums) 
    {
        if (nums.size()==0) return false;
        total = accumulate(nums.begin(), nums.end(), 0);
        if (total%4!=0) return false;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        return dfs(nums, 0, 0, 0);
    }

    bool dfs(vector<int>& nums, int cur, int group, int sum)
    {
        if (group==4) return true;
        if (sum > total/4) return false;
        if (sum == total/4)
            return dfs(nums, 0, group+1, 0);
        
        int last = -1;
        for (int i=cur; i<nums.size(); i++)
        {
            if (visited[i]==1) continue;
            if (nums[i]==last) continue;
            visited[i] = 1;            
            last = nums[i];
            if (dfs(nums, i+1, group, sum+nums[i]))
                return true;
            visited[i] = 0;
        }
        return false;
    }

};
