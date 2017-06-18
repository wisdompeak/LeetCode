class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        
        int i=0;
        int j=0;
        int count=0;
        
        while (j<nums.size())
        {
            if (nums[i]+k==nums[j] && i<j)
            {
                count++;
                while (nums[i]==nums[i+1])
                    i++;
                i++;    
            }
            else if (nums[i]+k>=nums[j])
                j++;
            else
                i++;
        }
        return count;       
    }
};
