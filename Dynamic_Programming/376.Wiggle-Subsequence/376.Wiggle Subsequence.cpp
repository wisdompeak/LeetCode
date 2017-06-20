class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if (nums.size()==0) return 0;
        
        int p=1;
        int q=1;
        
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>nums[i-1])
                p=q+1;
            else if (nums[i]<nums[i-1])
                q=p+1;
        }
        
        return max(p,q);
        
    }
};
