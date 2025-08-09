using ll = long long;
class Solution {
public:
    vector<pair<int, int>>split(vector<int>&arr) {
        int n = arr.size();
        vector<pair<int, int>> result;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && arr[j + 1] < arr[j]) {
                j++;
            }
            if (j > i) {
                result.push_back({i, j});
            }
            i = j+1;
        }
        return result;        
    }

    long long maxSumTrionic(vector<int>& nums) {
        int  n = nums.size();
        vector<pair<int,int>>arr = split(nums);
        
        ll ret = LLONG_MIN/2;
        
        for (int i=0; i<arr.size(); i++) {
            int x = arr[i].first, y = arr[i].second;
            if (x-1<0) continue;
            if (y+1>=n) continue;
            if(nums[x-1]>=nums[x]) continue;
            if(nums[y+1]<=nums[y]) continue;
            
            ll sum = nums[x-1];
            ll maxSum1 = nums[x-1];
            for (int j=x-2; j>=0; j--) {
                if (nums[j]>=nums[j+1]) break;
                sum += nums[j];
                maxSum1 = max(maxSum1, sum);
            }

            sum = nums[y+1];
            ll maxSum2 = nums[y+1];            
            for (int j=y+2; j<n; j++) {
                if (nums[j]<=nums[j-1]) break;
                sum += nums[j];
                maxSum2 = max(maxSum2, sum);
            }
            
            sum = accumulate(nums.begin()+x, nums.begin()+y+1, 0ll);
            ret = max(ret, maxSum1 + maxSum2 + sum);
        }

        return ret;        
    }
};
