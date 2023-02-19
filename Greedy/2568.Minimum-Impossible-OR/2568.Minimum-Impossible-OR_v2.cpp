class Solution {
public:
    int minImpossibleOR(vector<int>& nums) 
    {
        unordered_set<int>Set(nums.begin(), nums.end());
        for (int i=0; i<31; i++)
        {
            if (Set.find(1<<i)==Set.end())
                return (1<<i);
        }
        return -1;
    }
};
