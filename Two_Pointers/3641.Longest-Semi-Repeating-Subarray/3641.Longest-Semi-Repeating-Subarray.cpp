class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int,int>Map;
        int count = 0;
        int n = nums.size();
        int j = -1;
        int ret = 0;
        for (int i=0; i<n; i++) {
            while (j+1<n && count<=k) {                                
                Map[nums[++j]]++;
                if (Map[nums[j]]==2)
                    count++;                
            }       
            if (count>k)     
                ret = max(ret, j - i);
            else
                ret = max(ret, j - i + 1);
            Map[nums[i]]--;
            if (Map[nums[i]]==1) count--;
        }
        return ret;
        
    }
};
