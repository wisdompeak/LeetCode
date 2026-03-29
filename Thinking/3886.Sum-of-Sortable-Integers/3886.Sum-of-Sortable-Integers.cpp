class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int>divisors;
        for (int d=1; 1LL*d*d<=n; d++) {
            if (n%d==0) {
                divisors.push_back(d);
                if (d*d!=n) divisors.push_back(n/d);
            }
        }
        int ret = 0;
        for (int k: divisors) {
            if (checkOK(nums, k)) {
                ret+=k;
            }
                
        }
        return ret;
    }

    bool checkOK(vector<int>&nums, int k) {
        int n = nums.size();        
        bool first = true;
        int prevMax = 0;

        for (int s=0; s<n; s+=k) {
            int mn = nums[s], mx = nums[s];
            int desc = 0;

            for (int i=s; i<s+k; i++) {
                int j = (i+1==s+k)? s: (i+1);
                if (nums[i]>nums[j])
                    desc++;
                if (desc>1) return false;

                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
            }

            if (!first && prevMax > mn) return false;
            first = false;
            prevMax = mx;
        }
        return true;
    }
};
