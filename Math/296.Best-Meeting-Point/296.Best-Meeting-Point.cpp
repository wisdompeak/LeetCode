class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) 
    {
        vector<vector<int>>persons;
        int M = grid.size();
        int N = grid[0].size();
        
        vector<int>rows;
        vector<int>cols;
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
            {
                if (grid[i][j]==0) continue;
                rows.push_back(i);
                cols.push_back(j);
            }
        sort(cols.begin(),cols.end());
        int X = rows[rows.size()/2];
        int Y = cols[cols.size()/2];
                
        int result=0;
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
            {
                if (grid[i][j]==0) continue;
                result+=abs(i-X)+abs(j-Y);
            }
        return result;
    }
};
