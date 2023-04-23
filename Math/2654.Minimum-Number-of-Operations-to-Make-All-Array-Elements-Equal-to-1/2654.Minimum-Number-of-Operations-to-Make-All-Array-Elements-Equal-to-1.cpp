class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        int g = nums[0];
        for (int i=0; i<n; i++)
            g = gcd(g, nums[i]);
        
        if (g!=1) return -1;
        
        int count = 0;
        for (int i=0; i<n; i++)
            if (nums[i]==1) count++;
        if (count > 0)
            return (n - count);
        
        count = n;
        for (int i=0; i<n; i++)
        {
            int g = nums[i];
            for (int j=i; j<n; j++)
            {
                g = gcd(g, nums[j]);
                if (g == 1)
                {
                    count = min(count, j-i+1);                
                    break;
                }                    
            }
        }
                
        return count-1 + (n - 1);
    }
};
