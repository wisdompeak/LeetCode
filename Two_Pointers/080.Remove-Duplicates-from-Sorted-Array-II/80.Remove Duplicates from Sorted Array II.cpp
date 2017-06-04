class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        
        int i=1;
        for (int j=0; j<nums.size(); j++)
        {
            if (j==0 || j==1) 
                continue;
            else if (nums[j]==nums[i] && nums[j]==nums[i-1])
                continue;
            else
            {
                i++;
                nums[i]=nums[j];
            }
        }
        
        return i+1;
        
    }
};
