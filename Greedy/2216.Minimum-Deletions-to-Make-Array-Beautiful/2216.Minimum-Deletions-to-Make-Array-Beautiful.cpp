class Solution {
public:
    int minDeletion(vector<int>& nums) 
    {
        int n = nums.size();
        int ret = 0;
        
        int i = 0;        
        
        while (i<n)
        {            
            int j = i+1;
            while (j<n && nums[j]==nums[i])
            {
                ret++;
                j++;
            }
            
            if (j<n)
            {
                i = j+1;
            }
            else
            {
                ret++;
                break;
            }                
        }
        
        return ret;        
    }
};
