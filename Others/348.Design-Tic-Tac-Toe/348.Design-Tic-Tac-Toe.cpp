class TicTacToe {
    int Row[100];
    int Col[100];
    int Diag[2];
public:
    /** Initialize your data structure here. */
    int n;
    TicTacToe(int n) {        
        this->n = n;
        memset(Row, 0, sizeof(Row));
        memset(Col, 0, sizeof(Col));
        memset(Diag, 0, sizeof(Diag));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) 
    {       
        if (player==1)
        {
            Row[row]++;
            Col[col]++;
            if (row==col)
                Diag[0]++;
            if (row+col==n-1)
                Diag[1]++;
            
            if (Row[row]==n || Col[col]==n || Diag[0]==n || Diag[1]==n)
                return 1;            
        }
        if (player==2)
        {
            Row[row]--;
            Col[col]--;
            if (row==col)
                Diag[0]--;
            if (row+col==n-1)
                Diag[1]--;
            
            if (Row[row]==-n || Col[col]==-n || Diag[0]==-n || Diag[1]==-n)
                return 2;            
        }        
        // cout<<Row[row]<<" "<<Col[col]<<" "<<Diag[0]<<" "<<Diag[1]<<endl;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
