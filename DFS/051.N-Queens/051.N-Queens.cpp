class Solution {
    vector<vector<string>>results;
    vector<string>board;    
    int n;
public:
    vector<vector<string>>solveNQueens(int n) 
    {     
        this->n = n;           
        string s;
        for (int i=0; i<n; i++)
            s+=".";
        for (int i=0; i<n; i++)
            board.push_back(s);
                
        DFS(0);
        return results;
    }
    
    void DFS(int i)
    {                        
        if (i==n)
        {
            results.push_back(board);
            return;
        }
        for (int j=0; j<n; j++)
        {
            if (isValid(i,j))
            {
                board[i][j]='Q';
                DFS(i+1);
                board[i][j]='.';
            }                
        }        
    }
    
    bool isValid(int row, int col)
    {
        for (int i=0; i<row; i++)
            if (board[i][col]=='Q') return false;
        for (int j=0; j<col; j++)
            if (board[row][j]=='Q') return false;
        int k=1;
        while (row-k >= 0 && col-k >= 0)
        {
            if (board[row-k][col-k]=='Q') return false;
            k++;
        }
        k=1;
        while (row-k >= 0 && col+k < n)
        {
            if (board[row-k][col+k]=='Q') return false;
            k++;
        }
        return true;
    }
};
