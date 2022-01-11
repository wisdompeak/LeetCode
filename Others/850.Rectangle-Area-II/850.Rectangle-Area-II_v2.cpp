using ll = long long;
class Diff2d {    
public:
    vector<vector<int>>f;
    vector<vector<int>>diff;    
    int m,n;
    Diff2d(int m, int n)
    {
        this->m = m;
        this->n = n;
        diff.resize(m+1);
        f.resize(m+1);        
        for (int i=0; i<m+1; i++)
        {
            diff[i].resize(n+1);
            f[i].resize(n+1);
        }            
    }
    void set(int x0, int y0, int x1, int y1, int val)
    {
        diff[x0][y0]+=val;
        diff[x0][y1+1]-=val;
        diff[x1+1][y0]-=val;
        diff[x1+1][y1+1]+=val;
    }
    void compute()
    {
        f[0][0] = diff[0][0];
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int a = i==0?0:f[i-1][j];
                int b = j==0?0:f[i][j-1];
                int c = (i==0||j==0)?0:f[i-1][j-1];                
                f[i][j] = a + b - c + diff[i][j];
            }
    }    
};

class Solution {
    ll M = 1e9+7;
public:
    int rectangleArea(vector<vector<int>>& rectangles) 
    {
        set<ll>pointX;
        set<ll>pointY;
        for (auto rect: rectangles)
        {
            pointX.insert(rect[0]);
            pointY.insert(rect[1]);
            pointX.insert(rect[2]);
            pointY.insert(rect[3]);
        }
        
        vector<ll>row(pointX.begin(), pointX.end());
        vector<ll>col(pointY.begin(), pointY.end());
        
        unordered_map<ll,ll>X2idx;
        unordered_map<ll,ll>Y2idx;
        for (int i=0; i<row.size(); i++)
            X2idx[row[i]] = i;
        for (int i=0; i<col.size(); i++)
            Y2idx[col[i]] = i;
        
        int m = row.size(), n = col.size();
        Diff2d grid(m,n);

        for (auto rect: rectangles)
        {
            int i = X2idx[rect[0]];
            int j = Y2idx[rect[1]];
            int x = X2idx[rect[2]]-1;
            int y = Y2idx[rect[3]]-1;
            grid.set(i,j,x,y,1);
        }
        grid.compute();

        ll ret = 0;
        for (int i=0; i<m-1; i++)
            for (int j=0; j<n-1; j++)
            {
                if (grid.f[i][j]>0)
                {
                    ll dx = row[i+1]-row[i];
                    ll dy = col[j+1]-col[j];
                    ret += dx*dy%M;
                    ret %= M;
                }
            }
        return ret;
    }
};
