class Solution {
public:
    int missingElement(vector<int>& nums, int k) {        
        int left = nums[0];
        int right = nums.back()+k;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            int t = upper_bound(nums.begin(), nums.end(), mid) - nums.begin(); // how many nums <= mid in the array
            int s = mid-nums[0]+1; // how many nums <= mid            
            
            if (s-t >= k)  // how many missing between [nums[0], mid]
                right = mid;
            else
                left = mid+1;            
        }
        
        return left;
    }
};
