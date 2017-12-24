class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
        int count=0;
        long miss=1;
        int i=0;
        
        while (miss<=n)
        {
            if (i>=nums.size() || miss<nums[i])
            {
                count++;
                miss+=miss;
            }
            else
            {
                miss+=nums[i];
                i++;
            }
        }
        
        return count;
    }
};
