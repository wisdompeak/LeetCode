using LL = long long;
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) 
    {
        LL ret = 0;
        sort(coins.begin(), coins.end());
        ret = max(ret, helper(coins, k));
        
        for (auto& coin: coins)
        {
            int a = coin[0], b = coin[1];
            coin[0] = -b;
            coin[1] = -a;
        }
        sort(coins.begin(), coins.end());
        ret = max(ret, helper(coins, k));
        
        return ret;
    }
    
    LL helper(vector<vector<int>>& coins, int k)
    {
        int n = coins.size();
        int j = 0;
        LL sum = 0;
        LL ret = 0;
        for (int i=0; i<n; i++)
        {
            LL end = coins[i][0] + k -1;
            while (j<n && end >= coins[j][1])
            {
                sum += (LL)(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }
            LL extra = 0;
            if (j<n && end >= coins[j][0])
            {
                extra += (LL)(end - coins[j][0] + 1) * coins[j][2];
            }
            ret = max(ret, sum + extra);
            sum -= (LL)(coins[i][1]-coins[i][0]+1)*coins[i][2];            
        }
        return ret;        
    }
};
