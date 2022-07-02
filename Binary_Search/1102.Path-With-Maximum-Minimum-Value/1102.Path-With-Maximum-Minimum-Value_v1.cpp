class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) 
    {
        int left = 0, right = 1e9;        
        while (left<right)
        {
            int mid = right-(right-left)/2;
                        
            if (check(grid,mid))
                left = mid;
            else
                right = mid-1;
        }
        return left;        
    }
    
    bool check(vector<vector<int>> grid, int K)
    {
        if (grid[0][0]<K) return false;
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        int M = grid.size(), N = grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>visited(M, vector<int>(N));
        visited[0][0] = 1;
        
        while (q.size()>0)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=M||j<0||j>=N) continue;
                if (visited[i][j]) continue;                
                if (grid[i][j]<K) continue;
                if (i==M-1 && j==N-1) return true;
                visited[i][j] = 1;
                
                q.push({i,j});                
            }
        }
                
        return false;
    }
};
