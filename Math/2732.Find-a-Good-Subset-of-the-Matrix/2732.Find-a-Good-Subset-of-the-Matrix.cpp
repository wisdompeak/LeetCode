class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<m; i++)
        {
            int state = 0;
            for (int j=0; j<n; j++)
                if (grid[i][j])
                    state += (1<<j);
            Map[state].push_back(i);
            if (state == 0)
                return {i};                    
        }
        
        for (int i=0; i<m; i++)
        {
            int state = 0;
            for (int j=0; j<n; j++)
                if (grid[i][j])
                    state += (1<<j);
            
            for (int s = 0; s<(1<<5); s++)
            {
                int flag = 1;
                for (int j=0; j<n; j++)
                {
                    if (grid[i][j]==1 && ((s>>j)&1))
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag==0) continue;
                if (Map[s].size()==0) continue;
                
                for (int k: Map[s])
                {
                    if (k!=i)
                    {
                        vector<int>rets({i,k});
                        sort(rets.begin(), rets.end());
                        return rets;
                    }
                }
            }            
        }
        
        return {};
    }
};
