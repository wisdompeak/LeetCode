class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return quickselect(nums, 0, nums.size()-1, k);
    }

    int quickselect(vector<int>&nums, int a, int b, int k)
    {
        int pivot = nums[(a+b)/2];

        int i = a, j = b;       
        int t = a; 
        while (t <= j)
        {
            if (nums[t] < pivot)
            {
                swap(nums[i], nums[t]);
                i++;
                t++;
            }
            else if (nums[t] > pivot)
            {
                swap(nums[j], nums[t]);
                j--;
            }
            else
                t++;
        }

        if (b-j >= k)
            return quickselect(nums, j+1, b, k);
        else if ( b-i+1 >= k)
            return pivot;
        else
            return quickselect(nums, a, i-1, k-(b-i+1));        
    }
};
