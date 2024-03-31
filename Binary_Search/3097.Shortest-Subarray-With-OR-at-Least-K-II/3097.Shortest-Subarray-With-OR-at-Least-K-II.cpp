class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right-left)/2;
            if (isOK(nums, k, mid))
                right = mid;
            else
                left = mid+1;
        }
        if (!isOK(nums, k, left)) return -1;
        else return left;        
    }
    
    bool isOK(vector<int>&nums, int k, int len)
    {
        vector<int>count(31);
        for (int i=0; i<len-1; i++)
        {
            for (int j=0; j<31; j++)
                count[j] += ((nums[i]>>j)&1);
        }
        
        for (int i=len-1; i<nums.size(); i++)
        {
            for (int j=0; j<31; j++)
                count[j] += ((nums[i]>>j)&1);
            
            int sum = 0;
            for (int j=0; j<31; j++)
                if (count[j]>0) sum += (1<<j);
            
            if (sum >= k) return true;
            
            for (int j=0; j<31; j++)
                count[j] -= ((nums[i-len+1]>>j)&1);
        }
        
        return false;
    }
};
