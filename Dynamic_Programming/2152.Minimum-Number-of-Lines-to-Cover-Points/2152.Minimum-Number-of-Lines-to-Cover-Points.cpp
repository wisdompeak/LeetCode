class Solution {
public:
    int minimumLines(vector<vector<int>>& points) 
    {
        int n = points.size();
        vector<int>dp(1<<n, INT_MAX/2);
        
        for (int state = 1; state < (1<<n); state++)
        {
            if (__builtin_popcount(state)<=2)
                dp[state] = 1;
            else if (formLine(points, state))
                dp[state] = 1;            
        }
        
        for (int state = 1; state < (1<<n); state++)
        {
            for (int subset=state; subset>0; subset=(subset-1)&state)
            {
                dp[state] = min(dp[state], dp[subset] + dp[state-subset]);               
            }            
        }
        
        return dp[(1<<n)-1];
    }
    
    bool formLine(vector<vector<int>>& points, int state)
    {
        vector<int>temp;
        for (int i=0; i<points.size(); i++)
        {
            if (state%2==1)
                temp.push_back(i);
            state/=2;
        }        
        for (int i=1; i<temp.size(); i++)
        {
            int a = temp[0];
            int b = temp[1];
            int c = temp[i];
            if ((points[c][1]-points[a][1])*(points[b][0]-points[a][0])!=(points[b][1]-points[a][1])*(points[c][0]-points[a][0]))
                return false;
        }
        return true;            
    }
};
