class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return QuickSort(nums,nums.size()+1-k);
    }
    
    int QuickSort(vector<int>&nums, int n)
    {
        int pivot=nums[nums.size()/2];
        
        int count = 0;
        vector<int>small;
        vector<int>large;
        
        for (int k=0; k<nums.size(); k++)
        {
            if (nums[k]==pivot)
                count++;
            else if (nums[k]>pivot)
                large.push_back(nums[k]);
            else
                small.push_back(nums[k]);
        }
        
        if (n<=small.size())
            return QuickSort(small,n);
        else if (n>small.size()+count)
            return QuickSort(large,n-small.size()-count);
        else
            return pivot;
    }
};
