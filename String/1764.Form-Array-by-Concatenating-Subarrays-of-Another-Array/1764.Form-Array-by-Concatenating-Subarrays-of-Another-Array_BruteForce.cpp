class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) 
    {
        int cur = 0;
        for (int i=0; i<groups.size(); i++)
        {
            if (cur>=nums.size()) return false;
            cur = find(nums, cur, groups[i]);
            if (cur==-1) return false;
            cur += groups[i].size();
        }
        return true;
    }

    int find(vector<int>&nums, int cur, vector<int>&g)
    {
        for (int i=cur; i<nums.size(); i++)
        {
            int flag = 1;
            for (int j=0; j<g.size(); j++)
                if (cur+j>=nums.size() || nums[i+j]!=g[j])
                {
                    flag = 0;
                    break;
                }
            if (flag) return i;
        }
        return -1;
    }
};
