class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int N = nums.size();
        if (N==0) return false;
        
        vector<int>LeftMin(N,0);
        LeftMin[0] = INT_MAX;
        for (int i=1; i<N; i++)
            LeftMin[i] = min(LeftMin[i-1],nums[i-1]);
        
        vector<int>RightMax(N,0);
        RightMax[N-1] = INT_MIN;
        for (int i=N-2; i>=0; i--)
            RightMax[i] = max(RightMax[i+1],nums[i+1]);
        
        for (int i=1; i<N-1; i++)
        {
            if (LeftMin[i]<nums[i] && RightMax[i]>nums[i])
                return true;
        }
        return false;
        
    }
};
