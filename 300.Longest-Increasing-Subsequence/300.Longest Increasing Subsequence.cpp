class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int>q;
        
        for (int i=0; i<nums.size(); i++)
        {
            if (q.empty()) 
                q.push_back(nums[i]);
            else
            {
                auto pos = lower_bound(q.begin(),q.end(),nums[i]);
                if (pos!=q.end())
                    q[pos-q.begin()]=nums[i];
                else
                    q.push_back(nums[i]);
            }
                
        }
        
        return q.size();
        
    }
};
