typedef long long ll;
class Solution {
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
        vector<vector<ll>>sum(m, vector<ll>(n));
        vector<vector<ll>>diff(m, vector<ll>(n));
        
        for (auto rect: rectangles)
        {
            ll x0 = rect[0];
            ll y0 = rect[1];
            ll x1 = rect[2];
            ll y1 = rect[3];            
            diff[X2idx[x0]][Y2idx[y0]]+=1;
            diff[X2idx[x0]][Y2idx[y1]]-=1;
            diff[X2idx[x1]][Y2idx[y0]]-=1;
            diff[X2idx[x1]][Y2idx[y1]]+=1;            
        }
        
        
        ll ret = 0;
        ll M = 1e9+7;
        sum[0][0] = diff[0][0];
        if (diff[0][0]>0)
            ret += (row[1]-row[0])*(col[1]-col[0])%M;
        
        for (int i=0; i<m-1; i++)
            for (int j=0; j<n-1; j++)
            {
                if (i==0 && j==0) continue;                                 
                sum[i][j] = (i>=1?sum[i-1][j]:0) + (j>=1?sum[i][j-1]:0) - ((i>=1&&j>=1)?sum[i-1][j-1]:0) + diff[i][j];                                
                if (sum[i][j] > 0)
                    ret = (ret + (row[i+1]-row[i])*(col[j+1]-col[j])) % M;                                
            }
        
        return ret;
    }
};
