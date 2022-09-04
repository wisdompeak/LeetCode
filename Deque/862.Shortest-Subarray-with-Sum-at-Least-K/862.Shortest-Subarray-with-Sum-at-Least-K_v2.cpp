using LL = long long;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<LL>presum(n+1);        
        for (int i=0; i<nums.size(); i++)
            presum[i+1] = presum[i]+nums[i];

        int ret = INT_MAX;
        deque<int>dq;
        for (int i=0; i<=n; i++)
        {
            while (!dq.empty() && presum[dq.back()] >= presum[i])
                dq.pop_back();            

            while (!dq.empty() && presum[i]-presum[dq.front()] >= k) {                
                ret = min(ret, i-dq.front());
                dq.pop_front();
            }

            dq.push_back(i);
        }

        if (ret == INT_MAX) return -1;
        else return ret;
    }
};
