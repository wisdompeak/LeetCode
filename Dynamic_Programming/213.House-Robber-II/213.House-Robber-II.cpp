class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        
        int ret = 0;
        
        int rob = nums[1], norob = 0;        
        for (int i=2; i<n; i++)
        {
            int rob_tmp = rob, norob_tmp = norob;
            rob = norob_tmp + nums[i];
            norob = max(rob_tmp, norob_tmp);            
        }
        ret = max(rob, norob);
        
        rob = nums[0], norob =0;
        for (int i=1; i<n-1; i++)
        {
            int rob_tmp = rob, norob_tmp = norob;
            rob = norob_tmp + nums[i];
            norob = max(rob_tmp, norob_tmp);   
        }
        ret = max(ret, max(rob, norob));
        return ret;
        
    }
};
