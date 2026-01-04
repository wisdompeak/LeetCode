class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        unordered_map<int,int>count;
        unordered_map<int,int>forbid;
        for (int i=0; i<n; i++) {
            count[nums[i]]++;
            forbid[forbidden[i]]++;
        }

        for (auto [k,v]: count) {
            if (v > n - forbid[k]) return -1;
        }

        unordered_map<int, int>Map;
        for (int i=0; i<n; i++) {
            if (nums[i]==forbidden[i])
                Map[forbidden[i]]++;
        }

        vector<int>arr;
        for (auto [k,v]: Map)
            arr.push_back(v);
        if (arr.empty()) return 0;

        int total = accumulate(arr.begin(), arr.end(), 0);
        sort(arr.begin(), arr.end());
        int mx = arr.back();

        if (mx <= total-mx)
            return (total+1)/2;
        else
            return mx;
    }
};
