class Solution {
    unordered_map<int,int>Father;
    int M;
    int N;
    public:
    void solve(vector<vector<char>>& board)
    {
        M=board.size();
        if (M==0) return;
        N=board[0].size();
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (board[i][j]=='X') continue;
             if (i==0 || i==M-1 || j==0 || j==N-1)
                 Father[i*N+j]=-1;
             else
                 Father[i*N+j]=i*N+j;
         }

        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (board[i][j]=='X') continue;
             for (int k=0; k<4; k++)
             {
                 int x=i+dir[k].first;
                 int y=j+dir[k].second;
                 if (x<0||x>=M||y<0||y>=N) continue;
                 if (board[x][y]=='X') continue;
                 if (FindSet(x*N+y)!=FindSet(i*N+j))
                     Union(x*N+y,i*N+j);
             }
         }

        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (board[i][j]=='X') continue;
             if (FindSet(i*N+j)!=-1)
                 board[i][j]='X';
         }
    }

    int FindSet(int x)
    {
        if (Father[x]==-1)
            return -1;
        if (Father[x]!=x)
        {
            Father[x]=FindSet(Father[x]);
        }
        return Father[x];
    }

    void Union(int x,int y)
    {
        x=Father[x];
        y=Father[y];
        
        bool flag;
        if (x/N<y/N)
            flag=1;
        else if (x%N==y%N)
            flag=1;
        else
            flag=0;
        
        if (flag)        
            Father[y]=x;        
        else    
            Father[x]=y;        
    }
};
