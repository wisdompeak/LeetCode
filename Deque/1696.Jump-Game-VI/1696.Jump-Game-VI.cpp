class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deque<pair<int,int>>dq;
        dq.push_back({nums[0],0});
        for (int i=1; i<n; i++)
        {
            while (!dq.empty() && i - dq.front().second > k)
                dq.pop_front();

            int curSteps = dq.front().first + nums[i];
            while (!dq.empty() && curSteps > dq.back().first)
                dq.pop_back();
            dq.push_back({curSteps,i});
        }
        return dq.back().first;
    }
};
