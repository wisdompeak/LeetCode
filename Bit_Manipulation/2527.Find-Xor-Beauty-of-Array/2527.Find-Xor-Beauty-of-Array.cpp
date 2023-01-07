class Solution {
public:
    int xorBeauty(vector<int>& nums) 
    {
        int sum = 0;
        for (int x: nums)
            sum ^= x;
        return sum;
        
    }
};
