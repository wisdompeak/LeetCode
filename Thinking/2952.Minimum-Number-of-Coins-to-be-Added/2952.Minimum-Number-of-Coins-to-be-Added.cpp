class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) 
    {
        sort(coins.begin(), coins.end());
        int limit = 0;
        int i = 0;
        int ret = 0;
        while (limit < target)
        {
            if (i==coins.size() || limit+1 < coins[i])
            {
                ret++;
                limit += limit+1;
            }
            else
            {
                limit += coins[i];
                i++;
            }            
        }
        
        return ret;        
    }
};
