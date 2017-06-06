class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int curMax=INT_MIN;
        int right_bound=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]<curMax)
                right_bound=i;
            curMax=max(curMax,nums[i]);
        }
        
        int curMin=INT_MAX;
        int left_bound=nums.size()-1;
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (nums[i]>curMin)
                left_bound=i;
            curMin=min(curMin,nums[i]);
        }        
        
        cout<<left_bound<<" "<<right_bound<<endl;
        
        return left_bound>=right_bound?0:right_bound-left_bound+1;
    }
};
