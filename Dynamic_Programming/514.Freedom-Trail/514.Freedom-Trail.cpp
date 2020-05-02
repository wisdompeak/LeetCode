class Solution {
public:
    int findRotateSteps(string ring, string key) 
    {
        unordered_map<char,vector<int>>letter2pos;
        for (int i=0; i<ring.size(); i++)
            letter2pos[ring[i]].push_back(i);

        int n = key.size();
        int m = ring.size();
        auto dp = vector<vector<int>>(n, vector<int>(m, INT_MAX/2));

        for (int i=0; i<n; i++)
        {
            if (i==0)
            {
                for (int cur_pos : letter2pos[key[i]])
                    dp[i][cur_pos] = min(cur_pos, abs(m-cur_pos));                    
            }
            else if (i>=1)
            {
                for (int cur_pos : letter2pos[key[i]])                
                    for (int prev_pos : letter2pos[key[i-1]])                                        
                        dp[i][cur_pos] = min(dp[i][cur_pos], dp[i-1][prev_pos] + min(abs(cur_pos-prev_pos), m-abs(cur_pos-prev_pos)));                     
            }
        }

        int ret = INT_MAX;
        for (int pos: letter2pos[key[n-1]])
            ret = min(ret, dp[n-1][pos]);
        return ret+n;
    }
};
