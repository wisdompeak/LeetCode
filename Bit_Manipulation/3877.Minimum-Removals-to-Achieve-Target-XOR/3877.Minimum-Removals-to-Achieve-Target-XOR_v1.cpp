class Solution {
public:
    unordered_map<int,int>compute(vector<int>nums) {
        int n = nums.size();
        unordered_map<int,int>Map;
        Map[0] = 0;
        for (int mask = 0; mask < (1<<n); mask++) {
            int x = 0, cnt = 0;
            for (int i=0; i<n; i++) {
                if ((mask>>i)&1) {
                    x^=nums[i];
                    cnt++;
                }
            }
            if (!Map.count(x) || cnt<Map[x])
                Map[x] = cnt;
        }
        return Map;
    }

    int minRemovals(vector<int>& nums, int target) {
        int  n = nums.size();
        int total = 0;
        for (int x: nums) total^=x;

        int need = total^target;
        
        vector<int>left(nums.begin(), nums.begin()+n/2);
        vector<int>right(nums.begin()+n/2, nums.end());

        unordered_map<int,int>L = compute(left);
        unordered_map<int,int>R = compute(right);

        int ret = INT_MAX;
        for (auto [x1, c1]: L) {
            int x2= need^x1;
            if (R.count(x2)) {
                ret = min(ret, c1+R[x2]);
            }
        }
        if (ret!=INT_MAX)
            return ret;
        else
            return -1;
    }
};
