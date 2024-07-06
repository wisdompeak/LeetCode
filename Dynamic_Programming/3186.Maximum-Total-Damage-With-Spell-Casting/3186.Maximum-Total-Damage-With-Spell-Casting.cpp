class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) 
    {
        map<int, long long>Map;
        for (int x: power)
            Map[x]++;

        vector<pair<int, int>>spell(Map.begin(), Map.end());

        vector<long long>dp(spell.size());

        for (int i=0; i<spell.size(); i++)
        {
            auto [p, count] = spell[i];
            
            // do not pick the i-th spell
            dp[i] = (long long)p*count;

            // only pick the i-th spell
            if (i>=1) dp[i] = max(dp[i], dp[i-1]);

            // pick the i-th spell along with previous ones
            if (i>=1 && p - spell[i-1].first > 2)
                dp[i] = max(dp[i], dp[i-1] + p * count);
            else if (i>=2 && p - spell[i-2].first > 2)
                dp[i] = max(dp[i], dp[i-2] + p * count);
            else if (i>=3)
                dp[i] = max(dp[i], dp[i-3] + p * count);
        }

        return dp[spell.size()-1];        
    }
};
