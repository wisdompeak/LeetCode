class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deque<pair<int,int>>q;

        int ret = INT_MIN;
        for (int i=0; i<n; i++)
        {
            while (q.size() >0 && q.front().first < i-k)
                q.pop_front();
            
            int cur = nums[i];
            if (q.size()>0) cur = max(cur, nums[i]+q.front().second);
            ret = max(ret, cur);
            while (q.size()>0 && cur>q.back().second)
                q.pop_back();
            q.push_back({i,cur});
        }

        return ret;
    }
};
