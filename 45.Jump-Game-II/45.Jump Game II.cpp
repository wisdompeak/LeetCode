class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int N=nums.size();
        vector<int>dp(N,0);
        
        if (N==0) return 0;
        if (N==1) return 0;
        
        dp[0]=0;
        int left=0;
        int right=0;
        int far=0;
        int count=0;
        
        while (far<N-1)
        {
            for (int i=left; i<=right; i++)
            {
                if (i+nums[i]>far)
                    far=i+nums[i];
            }
            left=right+1;
            right=far;
            count++;
        }
        
        return count;
    
    }
};
