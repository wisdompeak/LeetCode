class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n = nums.size();
        unordered_map<int,int>Map;
        int presum = 0;
        Map[0] = -1;
        for (int i=0; i<n; i++)
        {
            presum += nums[i];
            if (Map.find(presum)==Map.end())
                Map[presum] = i;
        }
        
        int ret = INT_MAX;
        if (Map.find(x)!=Map.end())
            ret = Map[x]+1;
        
        int sufsum = 0;
        for (int b = n-1; b>=0; b--)
        {
            sufsum += nums[b];
            int pre = x - sufsum;
            if (Map.find(pre)!=Map.end())
            {
                int a = Map[pre];
                if (a<b)
                {
                    ret = min(ret, a+1 + n-b);
                }
            }
        }
        
        return ret==INT_MAX ? -1: ret;        
    }
};

