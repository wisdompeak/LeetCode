class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        auto dp = vector<vector<int>>(m,vector<int>(n,-1));
        auto paths = vector<vector<int>>(m,vector<int>(n,0));
        int M = 1e9+7;

        board[0][0] = '0';

        for (int i=m-1; i>=0; i--)
            for (int j=n-1; j>=0; j--)
            {
                if (i==m-1 && j==n-1)
                {
                    dp[i][j] = 0;
                    paths[i][j] = 1;
                    continue;
                }
                if (board[i][j]=='X')
                    continue;

                int right = -1, down = -1, diag = -1;
                if (j+1<n) right = dp[i][j+1];
                if (i+1<m) down = dp[i+1][j];
                if (i+1<m && j+1<n) diag = dp[i+1][j+1];
                dp[i][j] = max(max(right,down),diag);

                if (dp[i][j]==-1) continue;

                if (i+1<m && dp[i+1][j]!=-1 && dp[i][j]==down)
                    paths[i][j] = (paths[i][j]+paths[i+1][j])%M;
                if (j+1<n && dp[i][j+1]!=-1 && dp[i][j]==right)
                    paths[i][j] = (paths[i][j]+paths[i][j+1])%M;
                if (i+1<m && j+1<n && dp[i+1][j+1]!=-1 && dp[i][j]==diag)
                    paths[i][j] = (paths[i][j]+paths[i+1][j+1])%M;
                
                dp[i][j] += board[i][j]-'0';
            }
        return {dp[0][0]==-1?0:dp[0][0], paths[0][0]};
    }
};
