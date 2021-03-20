class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) 
    {
        sort(coins.begin(), coins.end());
        
        int curMax = 0;
        
        for (auto c: coins)
        {
            if (c>curMax+1) break;
            curMax+=c;
            
        }
        return curMax+1;
        
    }
};
