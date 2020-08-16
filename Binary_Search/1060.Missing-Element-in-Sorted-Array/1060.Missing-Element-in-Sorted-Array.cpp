class Solution {
public:
    int missingElement(vector<int>& nums, int k) {        
        int left = nums[0];
        int right = nums.back()+k;
        while (left < right)
        {
            int mid = right-(right-left)/2;
            
            int M = mid-nums[0]; // how many nums < mid            
            int T = lower_bound(nums.begin(), nums.end(), mid) - nums.begin(); // how many nums < mid in this array            
            int missing = M - T;
                        
            if (missing > k-1)
                right = mid-1;
            else
                left = mid;            
        }
        
        return left;
    }
};
