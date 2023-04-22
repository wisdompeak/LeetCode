using PII = pair<int,int>;
class Solution {    
public:
    int minimumVisitedCells(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();        
        
        vector<vector<int>>dp(m, vector<int>(n,INT_MAX/2));        
        vector<priority_queue<PII, vector<PII>, greater<>>> row_diff(m);
        vector<priority_queue<PII, vector<PII>, greater<>>> col_diff(n);
        vector<multiset<int>>row(m);
        vector<multiset<int>>col(n);        
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                while (!row_diff[i].empty() && row_diff[i].top().first == j)
                {
                    int x = row_diff[i].top().second;
                    if (x>0) row[i].insert(x);
                    else row[i].erase(row[i].find(-x));                   
                    row_diff[i].pop(); 
                }
                while (!col_diff[j].empty() && col_diff[j].top().first == i)
                {
                    int x = col_diff[j].top().second;
                    if (x>0) col[j].insert(x);
                    else col[j].erase(col[j].find(-x));                   
                    col_diff[j].pop(); 
                }
                int min_val = INT_MAX/2;
                if (!row[i].empty()) min_val = min(min_val, *row[i].begin());
                if (!col[j].empty()) min_val = min(min_val, *col[j].begin());
                dp[i][j] = min_val;
                if (i==0 && j==0) dp[i][j] = 1;
                // cout<<"dp "<<i<<" "<<j<<" "<<dp[i][j]<<endl;

                int step = grid[i][j];
                if (step==0) continue;
                row_diff[i].push({j+1, dp[i][j]+1});
                row_diff[i].push({j+1+step, -dp[i][j]-1});
                col_diff[j].push({i+1, dp[i][j]+1});
                col_diff[j].push({i+1+step, -dp[i][j]-1});
            }
        
        if (dp[m-1][n-1] == INT_MAX/2)                
            return -1;
        else
            return dp[m-1][n-1];
        
    }
};
