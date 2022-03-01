class Solution {
public:
    int buildWall(int height, int width, vector<int>& bricks) 
    {    
        unordered_set<int>Set(bricks.begin(), bricks.end());
        vector<int>plans;
        int m = width-1;
        for (int state=0; state<(1<<m); state++)
        {
            vector<int>temp({-1});
            for (int i=0; i<m; i++)
            {
                if ((state>>i)&1)
                    temp.push_back(i);
            }
            temp.push_back(width-1);
            
            int flag = 1;
            for (int i=1; i<temp.size(); i++)
            {
                if (Set.find(temp[i]-temp[i-1])==Set.end())
                {
                    flag = 0;
                    break;
                }
            }
            if (flag) plans.push_back(state);
        }
                
        if (height==1) return plans.size();
                
        vector<vector<int>>dp(height, vector<int>(plans.size()));
        int M = 1e9+7;
        for (int j=0; j<plans.size(); j++)
            dp[0][j] = 1;
        
        int ret = 0;
        for (int i=1; i<height; i++)
            for (int j=0; j<plans.size(); j++)
            {
                for (int k=0; k<plans.size(); k++)
                {
                    if ((plans[j]&plans[k])==0)
                        dp[i][j] = (dp[i][j] + dp[i-1][k])%M;
                }
                if (i==height-1)
                    ret = (ret + dp[i][j])%M;
            }
        return ret;
        
    }
};
