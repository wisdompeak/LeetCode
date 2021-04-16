class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
       bool temp = DFS(board, 0, 0);
    }
    
    bool DFS(vector<vector<char>>& board, int i, int j)
    {
        if (i==9) return true;
        if (j==9) return DFS(board, i+1, 0);
        if (board[i][j]!='.') return DFS(board, i, j+1);
        
        for (int k='1'; k<='9'; k++)
        {            
            if (!isValid(board, i, j, k)) continue;
            board[i][j]=k;
            if (DFS(board, i, j+1)) return true;                
            board[i][j]='.';
        }        
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j, char k)
    {        
        for (int row=0; row<9; row++)
        {
            if (row!=i && board[row][j] == k)
                return false;
        }
        for (int col=0; col<9; col++)
        {
            if (col!=j && board[i][col] == k)
                return false;
        }
        int m=i/3*3;
        int n=j/3*3;
        for (int p=m; p<m+3; p++)
         for (int q=n; q<n+3; q++)
         {
             if ((p!=i||q!=j)&&board[p][q]==k)
                 return false;
         }
        return true;
    }
};
