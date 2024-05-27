class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<int>nums;
        for (int x: nums1)
            if (x%k==0)
                nums.push_back(x/k);
        
        unordered_map<int, int> count;                
        for (int num : nums2) {
            count[num]++;
        }
        long long ret = 0;

        for (int x : nums) 
        {
            for (int d = 1; d * d <= x; ++d) 
            {
                if (x % d == 0) 
                {
                    if (count.find(d) != count.end()) {
                        ret += count[d];
                    }
                    if (d != x / d && count.find(x / d) != count.end()) {
                        ret += count[x / d];
                    }
                }
            }
        }

        return ret;        
    }
};
