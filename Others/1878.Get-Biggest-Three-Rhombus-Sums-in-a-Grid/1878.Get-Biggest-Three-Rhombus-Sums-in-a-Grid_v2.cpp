class Solution {
    int presum1[100][100]; // "\"
    int presum2[100][100]; // "/"    

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)            
                presum1[i][j] = ((i-1>=0 && j-1>=0) ? presum1[i-1][j-1] : 0) + grid[i][j];

        for (int i=0; i<m; i++)
            for (int j=n-1; j>=0; j--)            
                presum2[i][j] = ((i-1>=0 && j+1<n) ? presum2[i-1][j+1] : 0) + grid[i][j];

        unordered_set<int>Set;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                Set.insert(grid[i][j]);

                int R = min(i, j);
                R = min(R, m-1-i);
                R = min(R, n-1-j);

                for (int r = 1; r<=R; r++)
                {
                    int x1,x2, y1,y2;
                    int sum = 0;

                    x1 = i-r, y1 = j;
                    x2 = i, y2 = j+r;                    
                    sum += presum1[x2][y2] - ((x1-1>=0 && y1-1>=0) ? presum1[x1-1][y1-1] : 0);

                    x1 = i, y1 = j-r;
                    x2 = i+r, y2 = j;
                    sum += presum1[x2][y2] - ((x1-1>=0 && y1-1>=0) ? presum1[x1-1][y1-1] : 0);

                    x1 = i-r, y1 = j;
                    x2 = i, y2 = j-r;
                    sum += presum2[x2-1][y2+1]-presum2[x1][y1];

                    x1 = i, y1 = j+r;
                    x2 = i+r, y2 = j;
                    sum += presum2[x2-1][y2+1]-presum2[x1][y1];

                    Set.insert(sum);
                }
            }
        
        vector<int>rets(Set.begin(), Set.end());
        sort(rets.begin(), rets.end());
        reverse(rets.begin(), rets.end());
        while (rets.size()>3)
            rets.pop_back();
        return rets;        
    }
};
