class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int i = 0, j = n/2;
        int count = 0;
        for (int i=0; i<n/2; i++)
        {
            while (j<n && nums[i]*2>nums[j])
                j++;
            if (j<n)
            {
                count+=2;
                j++;
            }                
        }
        return count;
        
    }
};
