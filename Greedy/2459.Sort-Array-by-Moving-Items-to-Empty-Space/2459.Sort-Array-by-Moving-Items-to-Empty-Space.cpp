class Solution {
public:
    int sortArray(vector<int>& nums) 
    {
        int ret1 = helper(nums);
        nums.insert(nums.begin(), nums.back());
        nums.pop_back();
        int ret2 = helper(nums);
        return min(ret1, ret2);        
    }

    int helper(vector<int>nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i=0; i<n; i++)
        {    
            if (nums[i]==i) continue;                    
            if (i!=0) count+=2;
            while (nums[i]!=i)
            {
                swap(nums[i], nums[nums[i]]);
                count++;
            }
        }
        return count;
    }
};
