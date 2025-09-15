class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int>basis(32, 0);
        for (int x: nums) {
            for (int i=31; i>=0; i--) {
                if (!(x>>i)&1) continue;
                if (!basis[i]) {
                    basis[i] = x;
                    break;
                }
                x ^= basis[i];
            }
        }

        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            ans = max(ans, ans ^ basis[i]);
        }
        return ans;
    }
};
