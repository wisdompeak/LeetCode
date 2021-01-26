class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        for (int i=1; i<=n; i++)
        {
            while (nums[i]!=i && nums[i]<=n+1 && nums[i]!=nums[nums[i]])
            {
                swap(nums[i], nums[nums[i]]);
            }
        }
        
        for (int i=1; i<=n; i++)
        {
            if (nums[i]!=i)
               return {nums[i],i}; 
        }

        return {-1,-1};   
    }
};
