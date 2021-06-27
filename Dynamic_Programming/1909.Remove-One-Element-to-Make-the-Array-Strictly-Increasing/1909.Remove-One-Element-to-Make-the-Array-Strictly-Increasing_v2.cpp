class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int maxUsed = INT_MIN, maxNon = INT_MIN;
        
        for (int x: nums)
        {
            int maxUsed2 = maxUsed, maxNon2 = maxNon;
            maxNon = (x > maxNon2) ? x : INT_MAX;
            maxUsed = min((x > maxUsed2) ? x : INT_MAX, maxNon2);            
        }
        
        return maxUsed != INT_MAX || maxNon !=INT_MAX;
        
    }
};
