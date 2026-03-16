class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        int ret = 2;
        
        vector<int>left(n, 2);
        left[0] = 1;
        for (int i=2; i<n; i++) {
            int cur = nums[i]-nums[i-1];
            int pre = nums[i-1]-nums[i-2];
            if (cur==pre)
                left[i] = left[i-1]+1;
            else
                left[i] = 2;
            ret = max(ret, left[i] + (i!=n-1));
        }

        vector<int>right(n, 2);
        right[n-1] = 1;
        for (int i=n-3; i>=0; i--) {
            int cur = nums[i+1]-nums[i];
            int pre = nums[i+2]-nums[i+1];
            if (cur==pre)
                right[i] = right[i+1]+1;
            else
                right[i] = 2;
            ret = max(ret, right[i] + (i!=0));
        }
        
        for (int i=1; i<n-1; i++) {
            int ans = 3;
            int cur = nums[i+1]-nums[i-1];
            if (i+2<n && (nums[i+2]-nums[i+1])*2==cur)
                ans += right[i+1] - 1;
            if (i-2>=0 && (nums[i-1]-nums[i-2])*2==cur)
                ans += left[i-1] - 1;
            ret = max(ret, ans);
        }
        
        return ret;
    }
};
