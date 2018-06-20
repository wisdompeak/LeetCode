class Solution {
public:
    bool validTicTacToe(vector<string>& board) 
    {
        int O=0;
        int X=0;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
            {
                if (board[i][j]=='O')
                    O++;
                else if (board[i][j]=='X')
                    X++;
            }
        if (!(X==O || X-O==1)) return false;
        if (X==O && win(board,'X')) return false;
        if (X-O==1 && win(board,'O')) return false;
        return true;
    }
    
    bool win(vector<string>& board, char ch)
    {
        for (int i=0; i<3; i++)        
            if (board[i][0]==ch && board[i][1]==ch && board[i][2]==ch)
                return true;        
        for (int j=0; j<3; j++)        
            if (board[0][j]==ch && board[1][j]==ch && board[2][j]==ch)
                return true;        
        if (board[0][0]==ch && board[1][1]==ch && board[2][2]==ch)
            return true;
        if (board[2][0]==ch && board[1][1]==ch && board[0][2]==ch)
            return true;
        return false;
    }
};
