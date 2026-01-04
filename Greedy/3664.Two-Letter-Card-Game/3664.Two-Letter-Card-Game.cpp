class Solution {
public:
    int score(vector<string>& cards, char x) {
        unordered_map<string, int>Map1, Map2;
        int count3 = 0;
        for (string s: cards) {
            if (s[0]==x && s[1]!=x)
                Map1[s]++;
            else if (s[0]!=x && s[1]==x)
                Map2[s]++;
            else if (s[0]==x && s[1]==x)
                count3++;
        }
        vector<int>nums1;
        for (auto [k,v]:Map1) nums1.push_back(v);
        vector<int>nums2;
        for (auto [k,v]:Map2) nums2.push_back(v);        

        int ret = 0;
        for (int i=0; i<=count3; i++)
            ret = max(ret, solve(nums1, nums2, i,count3));

        return ret;
    }

    int solve(vector<int>nums1, vector<int>nums2, int x, int count3) {

        nums1.push_back(x);
        nums2.push_back(count3-x);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        return helper(nums1) + helper(nums2);
    }

    int helper(vector<int>nums) {
        if (nums.empty()) return 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int mx = nums.back();
        if (mx <= total -mx)
            return total/2;
        else
            return total-mx;
    }

};
