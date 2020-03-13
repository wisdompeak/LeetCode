class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int s0=0,s1=0;        
        
        int result=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==0)
            {
                s1 = s0+1;
                s0 = 0;                
            }
            else
            {
                s0++;
                s1++;
            }
            result = max(result,s0);
            result = max(result,s1);
        }
        
        return result;
    }
};
