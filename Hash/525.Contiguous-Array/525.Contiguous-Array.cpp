class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int>Map; // presum -> j
        Map[0] = -1;
        
        int ret = 0;
        int presum = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==1)
                presum += 1;
            else
                presum -= 1;
            
            if (Map.find(presum)!=Map.end())
                ret = max(ret, i - Map[presum]);
            else
                Map[presum] = i;
        }
        
        return ret;
    }
};
