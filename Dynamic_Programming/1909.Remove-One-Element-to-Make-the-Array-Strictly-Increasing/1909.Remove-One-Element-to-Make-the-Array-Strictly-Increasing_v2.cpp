class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int maxUsed = INT_MIN, maxNon = INT_MIN;
        
        for (int x: nums)
        {
            int maxUsed2 = maxUsed, maxNon2 = maxNon;
            maxNon = (x > maxNon2) ? x : INT_MAX;
            
            maxUsed = maxNon2;
            if (x>maxUsed2)
                maxUsed = min(maxUsed, x);            
        }
        
        return maxUsed != INT_MAX || maxNon !=INT_MAX;
        
    }
};
