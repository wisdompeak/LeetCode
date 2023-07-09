class Solution {
public:
    bool checkArray(vector<int>& nums, int k) 
    {
        if (k==1) return true;
        int n = nums.size();
        vector<int>diff(n+1, 0);
        
        int cur = 0;
        for (int i=0; i<n-1; i++)
        {
            cur += diff[i];
            if (cur>nums[i]) return false;
            int delta = nums[i] - cur;
            if (delta > 0 && i+k < n)
                diff[i+k] -= delta;
            cur += delta;
        }        
        
        return cur+diff[n-1] == nums[n-1];
    }
};
