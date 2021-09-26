class Solution {
    int m,n;
    vector<pair<int,int>>dir;
public:
    bool match(vector<vector<char>>& board, int i, int j, int k, string word)
    {
        for (int t=0; t<word.size(); t++)
        {
            int x = i+dir[k].first*t;
            int y = j+dir[k].second*t;
            if (x<0||x>=m||y<0||y>=n) return false;
            if (board[x][y]!=' '&&board[x][y]!=word[t])
                return false;
        }
        int t = word.size();
        int x = i+dir[k].first*t;
        int y = j+dir[k].second*t;
        if (x>=0&&x<m&&y>=0&&y<n&&board[x][y]!='#')
            return false;
        return true;
    }
    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) 
    {
        m = board.size();
        n = board[0].size();
        dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (board[i][j]!=' '&&board[i][j]!=word[0])
                    continue;
                for (int k=0; k<4; k++)
                {
                    int x = i-dir[k].first;
                    int y = j-dir[k].second;
                    if (x>=0 && x<m && y>=0 && y<n && board[x][y]!='#')
                        continue;
                    if (match(board, i,j,k, word))
                        return true;
                }
            }
        return false;                    
    }
};
