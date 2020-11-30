class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        
        for (int i=0; i<n; i++)            
            for (int j=0; j<i; j++)
            {
                if (nums[j]<nums[i])
                    left[i] = max(left[i], left[j]+1);                
            }
        
        for (int i=n; i>=0; i--)            
            for (int j=i+1; j<n; j++)
            {
                if (nums[j]<nums[i])
                    right[i] = max(right[i], right[j]+1);                
            }
        
        int count = 0;
        for (int i=0; i<n; i++)
        {
            if (left[i]>=2 && right[i]>=2)
                count = max(count, left[i]+right[i]-1);
        }
        
        return n-count;
    }
};
