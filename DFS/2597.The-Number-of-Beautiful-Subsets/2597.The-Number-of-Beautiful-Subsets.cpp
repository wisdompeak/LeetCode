class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        return dfs(0, 0, nums, k) - 1;
    }

    int dfs(int cur, int state, vector<int>& nums, int k)
    {
        if (cur==nums.size()) return 1;

        int flag = 1;
        for (int i=0; i<cur; i++)
        {
            if ((state>>i)&1 && (nums[i]+k==nums[cur] || nums[i]-k==nums[cur]))
            {
                flag = 0;
                break;
            }
        }

        int choose = dfs(cur+1, state+(1<<cur), nums, k);
        int notChoose = dfs(cur+1, state, nums, k);
        if (flag==1)
            return  choose + notChoose;
        else
            return notChoose;
    }
};
