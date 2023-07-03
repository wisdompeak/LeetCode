class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) 
    {
        int n = nums.size();          
        
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            int prevInvalid = -1;
            int prevLargerThanOne = -1;
            for (int j=i-1; j>=0; j--)
            {
                if (nums[j]==nums[i]+1)
                {
                    prevInvalid = j;
                    break;
                }
                if ((nums[j]>nums[i]+1) && prevLargerThanOne==-1)
                    prevLargerThanOne = j;
            }

            int afterInvalid = n;
            int afterLargerThanOne = n;
            for (int j=i+1; j<n; j++)
            {
                if ((nums[j]==nums[i]+1) || nums[j]==nums[i])
                {
                    afterInvalid = j;
                    break;
                }
                if ((nums[j]>nums[i]+1) && afterLargerThanOne==n)
                    afterLargerThanOne = j;
            }

            int a = i - prevInvalid;
            int b = afterInvalid - i;
            int c = i - max(prevInvalid, prevLargerThanOne);
            int d = min(afterInvalid, afterLargerThanOne) - i;

            ret += max(0, a*b - c*d);
        }
        
        return ret;        
    }
};
