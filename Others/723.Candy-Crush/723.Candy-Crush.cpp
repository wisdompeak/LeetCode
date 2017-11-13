class Solution {
    int M,N;
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) 
    {
        vector<vector<int>>newboard = board;
        
        M=board.size();
        N=board[0].size();
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
        int flag=0;
        
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (!canStart(board,visited,i,j)) continue;             
             
             for (int k=0; k<4; k++)
             {
                 vector<pair<int,int>>path;                                     
                 int x=i;
                 int y=j;                 
                 while (x>=0 && x<M && y>=0 && y<N && board[x][y]==board[i][j])
                 {                     
                     path.push_back({x,y});                     
                     x+=dir[k].first;
                     y+=dir[k].second;                     
                 }
                 if (path.size()>=3)
                 {
                     flag=1;
                     for (auto a:path)
                     {
                         newboard[a.first][a.second]=0;
                         visited[a.first][a.second]=1;
                     }                         
                 }                   
             }             
         }
                        
        /*
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
                cout<<newboard[i][j]<<" ";
            cout<<endl;
        }
        */
        
        for (int j=0; j<N; j++)
        {
            int a=M-1;
            int b=M-1;
            while (b>=0)
            {
                if (newboard[b][j]!=0)
                {
                   newboard[a][j]=newboard[b][j];
                    b--;
                    a--;
                }
                else
                    b--;
            }
            for (int i=a; i>=0; i--)
                newboard[i][j]=0;            
        }        
        
        if (flag==0)
            return board;
        else
            return candyCrush(newboard);
        
    }
    
    bool canStart(vector<vector<int>>& board,vector<vector<int>>& visited, int i, int j)
    {
        if (board[i][j]==0) return false;
        if (visited[i][j]==0) return true;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        
        for (int k=0; k<4; k++)
        {
            int x=i+dir[k].first;
            int y=j+dir[k].second;                        
            
            if (x>=0 && x<M && y>=0 && y<N && board[x][y]==board[i][j] && visited[x][y]==0)
                return true;        
        }
        return false;
    }
    
};
