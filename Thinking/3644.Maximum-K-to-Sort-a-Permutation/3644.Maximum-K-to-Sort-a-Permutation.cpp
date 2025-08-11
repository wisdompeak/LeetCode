class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int required_mask = -1; 
        bool is_sorted = true;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                is_sorted = false;
                required_mask &= i;
            }
        }

        if (is_sorted) { 
            return 0;
        }else {
            return required_mask;
        }
    }
};
