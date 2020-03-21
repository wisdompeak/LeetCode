### 417.Pacific-Atlantic-Water-Flow

此题DFS和BFS都适用，但一般用DFS的递归写起来比BFS更简洁。
```cpp
    void DFS(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& visited)
    {
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        
        for (int k=0; k<4; k++)
        {
            visited[i][j]=1;
            int m=i+dir[k].first;
            int n=j+dir[k].second;

            if (m<0 || m==M || n<0 || n==N) continue;
            if (visited[m][n]==1) continue;
            if (matrix[m][n]<matrix[i][j]) continue;            
            
            DFS(m,n,matrix,visited);
        }
    }
```    


[Leetcode Link](https://leetcode.com/problems/pacific-atlantic-water-flow)