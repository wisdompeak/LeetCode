class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int i=0;
        int j=0;
        int sum=0;
        int len=INT_MAX;
        
        for (int j=0; j<nums.size(); j++)
        {
            sum+=nums[j];
            
            if (sum<s)
                continue;
            else
            {
                while (sum>=s)
                {
                    len=min(len,j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
        }
        
        if (len==INT_MAX)
            len=0;
        
        return len;
    }
};
