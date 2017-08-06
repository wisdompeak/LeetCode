class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if (nums.size()==1) return nums[0];
        
        vector<int>f(nums.size(),0);
        vector<int>g(nums.size(),0);
        
        f[0]=nums[0];
        g[0]=nums[0];
        
        for (int i=1; i<nums.size(); i++)
        {
            f[i] = max(nums[i],max(f[i-1]*nums[i],g[i-1]*nums[i]));
            g[i] = min(nums[i],min(f[i-1]*nums[i],g[i-1]*nums[i]));
        }

        
        int result=INT_MIN;
        for (int i=0; i<nums.size(); i++)
            result=max(result,f[i]);
            
        return result;
        
        
    }
};
