class Solution {
    int m,n;
public:
    int minFlips(vector<vector<int>>& mat) 
    {
        m = mat.size();
        n = mat[0].size();
        if (check(mat,0)) return 0;

        for (int k=1; k<=m*n; k++)
        {
            int state = (1 << k) - 1;                                  
            while (state < (1 << (m*n)))
            {
                if (check(mat, state))
                    return k;

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }
        return -1;
    }

    bool check(vector<vector<int>>& mat, int state)
    {
        auto temp = mat;
        auto dir = vector<pair<int,int>>({{0,1},{0,-1},{1,0},{-1,0},{0,0}});        

        for (int s=0; s<(m*n); s++)
        {
            int t = state%2;            
            state/=2;
            if (t==0) continue;

            int i = s/n;
            int j = s%n;

            for (int k=0; k<5; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                temp[x][y] = 1-temp[x][y];
            }            
        }

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (temp[i][j]!=0) return false;
        return true;
    }
};
