class Solution {
public:
    int waysToMakeFair(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>leftEven(n+1);
        vector<int>leftOdd(n+1);
        int rightEven = 0, rightOdd = 0;
        nums.insert(nums.begin(),0);
        for (int i=1; i<=n; i++)
        {
            if (i%2==0)
                rightEven+=nums[i];
            else
                rightOdd+=nums[i];
            leftEven[i] = rightEven;
            leftOdd[i] = rightOdd;
        }
        
        rightEven = 0, rightOdd = 0;
        int ret = 0;
        for (int i=n; i>=1; i--)
        {
            if (leftEven[i-1]+rightOdd == leftOdd[i-1]+rightEven)
                ret++;
                
            if (i%2==0)
                rightEven+=nums[i];
            else
                rightOdd+=nums[i];            
        }
        return ret;
        
    }
};
