class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if (nums.size()==0) return 0;

        int ret = 1, dir = -2;
        for (int i=1; i<nums.size(); i++)
        {
            int dir_pre = dir;
            
            if (nums[i]-nums[i-1]>0)
                dir = 1;
            else if (nums[i]-nums[i-1]<0)
                dir = -1;
            else   
                dir = 0;

            if (dir==0)
                dir = dir_pre;
            else if (dir!=dir_pre)
                ret++;
        }

        return ret;
    }
};
