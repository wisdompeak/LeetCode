class Solution {
public:
    int MaximumProduct(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int N=nums.size();
        return max(nums[0]*nums[1]*nums[N-1], nums[N-3]*nums[N-2]*nums[N-1]);
    }
};
