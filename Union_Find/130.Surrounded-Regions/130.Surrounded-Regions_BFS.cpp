class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int M=board.size();
        if (M==0) return;
        int N=board[0].size();
        
        for (int i=0; i<M; i++)
        {
            if (board[i][0]=='O') BFS(i,0,board);
            if (board[i][N-1]=='O') BFS(i,N-1,board);
        }
        
        for (int j=0; j<N; j++)
        {
            if (board[0][j]=='O') BFS(0,j,board);
            if (board[M-1][j]=='O') BFS(M-1,j,board);
        }
        
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (board[i][j]=='#') 
                 board[i][j]='O';
             else if (board[i][j]=='O') 
                 board[i][j]='X';
         }        
            
    }
    
    void BFS(int i, int j, vector<vector<char>>& board)
    {
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        q.push({i,j});
        board[i][j]='#';
        int M=board.size();
        int N=board[0].size();
        
        while (!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;            
            q.pop();
            
            for (int k=0; k<4; k++)
            {
                int m=x+dir[k].first;
                int n=y+dir[k].second;
                if (m<0||m>=M||n<0||n>=N)
                    continue;
                if (board[m][n]!='O')
                    continue;
                board[m][n]='#';
                q.push({m,n});
            }
        }
    }    
    
};
