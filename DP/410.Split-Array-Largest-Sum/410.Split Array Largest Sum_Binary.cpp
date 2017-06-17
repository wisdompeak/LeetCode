class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int left=INT_MIN;
        int right = 0;
        for (int i=0; i<nums.size(); i++)
        {
            left = max(left,nums[i]);
            right += nums[i];
        }
        
        int mid;
        
        while (left<right)
        {
            mid = left+(right-left)/2;
            
            if (ItWorks(nums,m,mid))
                right = mid;
            else
                left = mid+1;
        }
        
        return left;
        
    }
    
    bool ItWorks(vector<int>& nums, int m, int k)
    {
        int sum=0;
        int count=1;
        
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]>k) return false;
            
            sum+=nums[i];
            if (sum>k)
            {
                sum=nums[i];
                count++;
            }
            
            if (count>m) return false;
        }
        
        return true;
        
    }
    
};
