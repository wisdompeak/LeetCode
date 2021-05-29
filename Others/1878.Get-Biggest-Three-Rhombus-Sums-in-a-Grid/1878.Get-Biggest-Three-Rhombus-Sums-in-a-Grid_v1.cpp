class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();        
        unordered_set<int>Set;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int R = min(i, j);
                R = min(R, m-1-i);
                R = min(R, n-1-j);
                
                Set.insert(grid[i][j]);
                
                for (int r = 1; r <= R; r++)
                {
                    int a,b;
                    a = i-r, b = j;
                    int sum = 0;
                    for (int k=0; k<r; k++)
                    {
                        a+=1;
                        b-=1;
                        sum+=grid[a][b];
                    }
                    for (int k=0; k<r; k++)
                    {
                        a+=1;
                        b+=1;
                        sum+=grid[a][b];
                    }
                    for (int k=0; k<r; k++)
                    {
                        a-=1;
                        b+=1;
                        sum+=grid[a][b];
                    }
                    for (int k=0; k<r; k++)
                    {
                        a-=1;
                        b-=1;
                        sum+=grid[a][b];
                    }
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
