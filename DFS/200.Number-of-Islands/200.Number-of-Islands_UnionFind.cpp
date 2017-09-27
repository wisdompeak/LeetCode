class Solution {
    unordered_map<int,int>Father;
    int M;
    int N;
    public:
    int numIslands(vector<vector<char>>& grid)
    {
        M=grid.size();
        if (M==0) return 0;
        N=grid[0].size();
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             Father[i*N+j]=i*N+j;
         }

        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (grid[i][j]=='0')
                 continue;
             
             for (int k=0; k<4; k++)
             {
                 int x=i+dir[k].first;
                 int y=j+dir[k].second;
                 if (x<0||x>=M||y<0||y>=N)
                     continue;
                 if (grid[x][y]=='0')
                     continue;                 
                 if (FindSet(x*N+y)!=FindSet(i*N+j))
                     Union(x*N+y,i*N+j);
             }
         }    
        
        unordered_set<int>Set;
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (grid[i][j]=='0') continue;
             Set.insert(FindSet(i*N+j));
         }
        
        return Set.size();

    }
    
    int FindSet(int x)
    {
        if (x!=Father[x])
            Father[x]=FindSet(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x=Father[x];
        y=Father[y];
        bool flag;
        if (x/N<y/N)
            flag=true;
        else if (x/N==y/N && x%N<=y%N)
            flag=true;
        else
            flag=false;

        if (flag)
            Father[y]=x;
        else
            Father[x]=y;
    }
};

