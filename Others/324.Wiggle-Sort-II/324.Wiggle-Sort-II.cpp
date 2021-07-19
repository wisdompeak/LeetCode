class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        int n = nums.size();
        auto sorted = nums;
        sort(sorted.begin(), sorted.end());
        int i = (n-1)/2, j = n-1;

        int sign = 1;
        for (int k=0; k<n; k++)
        {
            if (sign==1)
            {
                nums[k] = sorted[i];
                i--; 
            }
            else
            {
                nums[k] = sorted[j];
                j--; 
            }
            sign = 1-sign;
        }
        
    }
};
