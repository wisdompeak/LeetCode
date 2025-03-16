class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        int left = 0, right = queries.size();
        while (left < right)
        {
            int mid = left+(right-left)/2;
            if (isOK(nums, queries, mid))
                right = mid;
            else
                left = mid+1;
        }
        if (isOK(nums,queries, left)) return left;
        else return -1;        
    }
    
    bool isOK(vector<int>& nums, vector<vector<int>>& queries, int t)
    {
        int n = nums.size();
        vector<vector<int>>diff(n+1);
        for (int i=0; i<t; i++)
        {
            int l = queries[i][0], r = queries[i][1], v = queries[i][2];
            diff[l].push_back(v);
            diff[r+1].push_back(-v);
        }
        multiset<int>Set;
        for (int i=0; i<n; i++)
        {
            for (int x: diff[i])
            {
                if (x>0) Set.insert(x);
                else Set.erase(Set.lower_bound(-x));
            }
            if (!subsetSum(Set, nums[i]))
                return false;
        }
        return true;
    }
    
    bool subsetSum(multiset<int>& nums, int target) 
    {
        vector<bool> dp(target + 1, false);
        dp[0] = true; 
        for (int num : nums) 
        {
            for (int j = target; j >= num; j--) {
                if (dp[j - num])
                    dp[j] = true;
            }
        }
        return dp[target];
    }
};
