class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        
        int i=0;
        int j=1;
        int result=0;
        
        while (j<nums.size())
        {
            while (nums[j]<nums[i]+k) j++;
            if (nums[j]==nums[i]+k)
                result++;
            i++;
            while (i<nums.size() && nums[i]==nums[i-1]) i++;
            j=max(j,i+1);
        }
        
        return result;
    }
};
