class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int left = 0, right = 1000000;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            if (isOK(heights, mid))
                right = mid;
            else
                left = mid+1;           
            
        }
        return left;
    }

    bool isOK(vector<vector<int>>& heights, int a)
    {
        int m = heights.size();
        int n = heights[0].size();
        auto visited = vector<vector<int>>(m, vector<int>(n,0));
        visited[0][0] = 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=m||j<0||j>=n)
                    continue;
                if (visited[i][j]==1)
                    continue;
                if (abs(heights[i][j]-heights[x][y])>a)
                    continue;
                q.push({i,j});
                visited[i][j]=1;
            }
        }
        return visited[m-1][n-1]==true;
    }
};
