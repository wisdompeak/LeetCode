class Solution {
    unordered_map<char, pair<int,int>>Map[4];
    int dp[21][21][21][21];
    unordered_map<string, vector<int>>planMemo;
public:
    bool cross(pair<int,int>&a, pair<int,int>&b)
    {
        if (a.second < b.first) return false;
        if (b.second < a.first) return false;
        if (a.first < b.first && a.second > b.second) return false;
        if (b.first < a.first && b.second > a.second) return false;
        return true;
    }
    
    vector<int>strategy(string cars)
    {
        if (planMemo.find(cars)!=planMemo.end())
            return planMemo[cars];
        
        vector<int>rets;
        for (int state=1; state<(1<<4); state++)
        {
            int flag = 1;
            for (int i=0; i<4; i++) 
            {
                if (((state>>i)&1) && cars[i]=='#')
                    flag = 0;
            }
            if (flag == 0) continue;
                        
            vector<pair<int,int>>lines;
            for (int i=0; i<4; i++)
            {
                if ((state>>i)&1) 
                {
                    auto [start,end] = Map[i][cars[i]];
                    int a = min(start, end);
                    int b = max(start, end);                
                    lines.push_back({a,b});                    
                }                
            }            
            
            for (int i=0; i<lines.size(); i++)
                for (int j=i+1; j<lines.size(); j++)
                    if (cross(lines[i], lines[j]))
                    {
                        flag = 0;
                        break;
                    }
            
            if (flag == 1)
                rets.push_back(state);
        }
        
        planMemo[cars] = rets;
        return rets;
    }

    int trafficCommand(vector<string>& directions) 
    {        
        Map[0]['S'] = {0,3};
        Map[0]['W'] = {0,5};
        Map[0]['N'] = {0,7};
        Map[1]['W'] = {2,5};
        Map[1]['N'] = {2,7};
        Map[1]['E'] = {2,1};
        Map[2]['N'] = {4,7};
        Map[2]['E'] = {4,1};
        Map[2]['S'] = {4,3};
        Map[3]['E'] = {6,1};
        Map[3]['S'] = {6,3};
        Map[3]['W'] = {6,5};
        
        int n0 = directions[0].size();
        int n1 = directions[1].size();
        int n2 = directions[2].size();
        int n3 = directions[3].size();
        
        directions[0]+="#";
        directions[1]+="#";
        directions[2]+="#";
        directions[3]+="#";
        
        for (int i=0; i<=n0; i++)
            for (int j=0; j<=n1; j++)
                for (int k=0; k<=n2; k++)
                    for (int t=0; t<=n3; t++)
                        dp[i][j][k][t] = INT_MAX/2;
        dp[0][0][0][0] = 0;
        
        for (int i=0; i<=n0; i++)
            for (int j=0; j<=n1; j++)
                for (int k=0; k<=n2; k++)
                    for (int t=0; t<=n3; t++)
                    {
                        string cars;
                        cars.push_back(directions[0][i]);
                        cars.push_back(directions[1][j]);
                        cars.push_back(directions[2][k]);
                        cars.push_back(directions[3][t]);
                        
                        vector<int>plans = strategy(cars);                        
                        for (int plan : plans)
                        {                            
                            int ii = i+ ((plan>>0)&1);
                            int jj = j+ ((plan>>1)&1);
                            int kk = k+ ((plan>>2)&1);
                            int tt = t+ ((plan>>3)&1);
                            dp[ii][jj][kk][tt] = min(dp[ii][jj][kk][tt], dp[i][j][k][t]+1);                            
                       }
                    }
        
        return dp[n0][n1][n2][n3];
    }
};
