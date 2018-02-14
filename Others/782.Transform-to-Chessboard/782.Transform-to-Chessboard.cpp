class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) 
    {        
        int N=board.size();
        
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            {
                if (board[0][0]^board[i][0]!=board[0][j]^board[i][j]) return -1;
                if (board[0][0]^board[0][j]!=board[i][0]^board[i][j]) return -1;
            }
                
        int row1=0;
        for (int i=0; i<N; i++)
            if (board[i][0]==1) row1++;
        if (abs(N-row1*2)>1) return -1;
        
        int col1=0;
        for (int j=0; j<N; j++)
            if (board[0][j]==1) col1++;
        if (abs(N-col1*2)>1) return -1;        
        
        /****/
        
        int result=0;
        
        int countDiff1=0;
        for (int i=0; i<N; i++)
            if (board[i][0]!=i%2) countDiff1++;
                
        int countDiff2=0;
        for (int j=0; j<N; j++)
            if (board[0][j]!=j%2) countDiff2++;
        
        if (N%2==0)
        {
            result+=min(countDiff1,N-countDiff1)/2;
            result+=min(countDiff2,N-countDiff2)/2;
        }
        else
        {
            if (countDiff1%2==1) countDiff1=N-countDiff1;
            result+=countDiff1/2;
            if (countDiff2%2==1) countDiff2=N-countDiff2;
            result+=countDiff2/2;
        }
        
        return result;
        
    }
};
