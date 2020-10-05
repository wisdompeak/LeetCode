class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = nums.size()-1;
        for (int x=N; x>=0; x--)
        {
            while (i>=0 && nums[i]>=x)
            {
                count += 1;
                i--;
            }
                
            if (count == x)
                return x;
        }
        return -1;
    }
};
