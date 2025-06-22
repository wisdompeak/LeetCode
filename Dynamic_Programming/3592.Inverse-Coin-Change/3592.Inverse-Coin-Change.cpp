class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        numWays.insert(numWays.begin(), 0);

        vector<int>rets;
        vector<int>dp(n+1);
        dp[0] = 1;
        for (int c=1; c<=n; c++) {
            if (numWays[c] == dp[c])
                continue;
            rets.push_back(c);
            for (int i=c; i<=n; i++) {
                dp[i] += dp[i-c];
            }
        }

        for (int i=1; i<=n; i++) {
            if (dp[i]!=numWays[i])
                return {};
        }

        return rets;        
    }
};
