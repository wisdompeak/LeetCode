class Solution {    
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1] < b[1];
    }
public:
    int maxValue(vector<vector<int>>& events, int k) 
    {        
        sort(events.begin(), events.end(), cmp);
        int m = events.size();
        auto dp = vector<vector<int>>(m+1, vector<int>(k+1,INT_MIN/2));
        
        events.insert(events.begin(), events[0]);
        vector<int>endTime({0});
        
        int ret = 0;        
        for (int i=0; i<=m; i++)
            dp[i][0] = 0;
        
        for (int i=1; i<=m; i++)
        {
            auto iter = lower_bound(endTime.begin(), endTime.end(), events[i][0]);
            int t = iter-endTime.begin()-1;
            
            for (int j=1; j<=k; j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[t][j-1]+events[i][2]);                                
                ret = max(ret, dp[i][j]);
            }
            endTime.push_back(events[i][1]);
        }
        
        return ret;        
    }
};
