class Solution {
    int dp[1000];
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        int n = scores.size();
        vector<pair<int,int>>players(n);
        for (int i=0; i<n; i++)
            players[i] = {ages[i], scores[i]};
        sort(players.begin(), players.end());
        
        
        dp[0] = players[0].second;
        for (int i=1; i<n; i++)
        {          
            dp[i] = players[i].second;
            for (int j=0; j<i; j++)
            {
                if ((players[j].first < players[i].first && players[j].second <= players[i].second) || players[j].first == players[i].first)
                    dp[i] = max(dp[i], dp[j]+players[i].second);
            }                
        }
        
        int ret = 0;
        for (int i=0; i<n; i++)
            ret = max(ret, dp[i]);
        
        return ret;
    }
};
