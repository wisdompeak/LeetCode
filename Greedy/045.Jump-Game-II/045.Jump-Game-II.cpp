class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int start = 0, end = 0;
        int step = 0;
        if (nums.size()==1) return 0;

        while (end >= start)
        {
            int start_old = start;
            int end_old = end;            
            for (int i=start_old; i<=end_old; i++)            
            {
                end = max(end, i+nums[i]);
                if (end >= nums.size()-1)
                    return step+1;
            }
            step++;
            start = end_old+1;
        }
        return 0;
    }
};
