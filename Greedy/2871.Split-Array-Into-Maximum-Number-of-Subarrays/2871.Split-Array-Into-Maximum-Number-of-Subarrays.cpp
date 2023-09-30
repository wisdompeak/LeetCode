class Solution {
public:
    int maxSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            int j = i;
            int x = nums[i];
            while (j+1<n && x!=0)
            {
                j++;
                x&=nums[j];
            }
            if (x==0)
                ret++;
            i = j;
        }
        return max(ret,1 );
        
    }
};
