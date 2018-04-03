class Solution {
public:
    bool xorGame(vector<int>& nums) 
    {
        int x=0;
        for (int i=0; i<nums.size(); i++)
            x^=nums[i];
        return (x==0 || nums.size()%2==0);
    }
};
