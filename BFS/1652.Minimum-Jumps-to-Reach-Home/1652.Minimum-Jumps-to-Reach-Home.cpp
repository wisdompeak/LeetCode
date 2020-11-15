class Solution {
    int dp[6001][2];
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) 
    {
        if (x==0) return 0;
        int max_forbid = *max_element(forbidden.begin(), forbidden.end());
        int limit = x + b + max_forbid;

        for (int i=0; i<=limit; i++)
        {
            dp[i][0] = INT_MAX/2;
            dp[i][1] = INT_MAX/2;
        }
        for (auto x:forbidden)
        {
            dp[x][0] = -1;
            dp[x][1] = -1;
        }
        dp[0][0] = 0;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int i = q.front().first;
                int k = q.front().second;
                q.pop();

                if (i+a < limit && dp[i+a][0]!=-1 && dp[i+a][0] > dp[i][k]+1)
                {
                    dp[i+a][0] = dp[i][k]+1;
                    q.push({i+a,0});
                    if (i+a==x) return dp[i+a][0];
                }
                
                if (k==0)
                {
                    if (i-b>=0 && dp[i-b][1]!=-1 && dp[i-b][1] > dp[i][k]+1)
                    {
                        dp[i-b][1] = dp[i][k]+1;
                        q.push({i-b,1});
                        if (i-b==x) return dp[i-b][1];
                    }
                }
            }
        }
        return -1;
    }
};
