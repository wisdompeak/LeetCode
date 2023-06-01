class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) 
    {
        sort(nums.rbegin(), nums.rend());
        int left = 0, right = INT_MAX/2;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            if (isOK(mid, nums, x, y))
                right = mid;
            else
                left = mid+1;
        }
        return left;        
    }

    bool isOK(int k, vector<int>& nums, int x, int y) 
    {
        int count = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] < k*1.0*y) continue;
            count += ceil((nums[i] - k*1.0*y)/(x-y));
            if (count > k) return false;
        }
        return true;
    }
};
