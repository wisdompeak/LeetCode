class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        if (nums.size()<2) return 0;
        
        sort(nums.begin(),nums.end());
        
        int i=0;
        int j=1;
        int count=0;
        
        while (j<nums.size())
        {
            j=i+1;
            while (j<nums.size() && nums[j]<nums[i]+k) j++;
            if (j<nums.size() && nums[j]==nums[i]+k)
                count++;
            i++;
            while (i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        
        return count;

    }
};
