using LL = long long;
using PLI = pair<LL, int>;
class Solution {
public:
    long long kSum(vector<int>& nums, int k) 
    {
        LL sum = 0;
        for (int x: nums)        
            if (x>0) sum += x;
        if (k==1) return sum;
        
        for (int& x: nums)
            x = abs(x);
        sort(nums.begin(), nums.end());

        priority_queue<PLI, vector<PLI>, greater<>>pq;
        pq.push({nums[0],0});

        for (int t=0; t<k-1; t++)
        {
            auto [cur, i] = pq.top();
            pq.pop();
            if (t==k-2) return sum - cur;
            
            if (i+1 < nums.size())
            {
                pq.push({cur+nums[i+1], i+1});
                pq.push({cur-nums[i]+nums[i+1], i+1});
            }            
        }

        return -1;
    }
};
