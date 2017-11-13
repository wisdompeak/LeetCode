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
             if (board[i][j]==0 || visited[i][j]==1) continue;
             
             int x1=i;
             int x2=i;
             while (x1-1>=0 && board[x1-1][j]==board[i][j])
                 x1--;
             while (x2+1<M && board[x2+1][j]==board[i][j])
                 x2++;
             if (x2-x1+1>=3)
             {
                 flag=1;
                 for (int ii=x1; ii<=x2; ii++)
                 {
                     visited[ii][j]=1;
                     newboard[ii][j]=0;
                 }
             }
             
             int y1=j;
             int y2=j;
             while (y1-1>=0 && board[i][y1-1]==board[i][j])
                 y1--;
             while (y2+1<N && board[i][y2+1]==board[i][j])
                 y2++;
             if (y2-y1+1>=3)
             {
                 flag=1;
                 for (int jj=y1; jj<=y2; jj++)
                 {
                     visited[i][jj]=1;
                     newboard[i][jj]=0;
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
};
