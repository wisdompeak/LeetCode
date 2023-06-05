using LL = long long;
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int>row(n, -1);
        vector<int>col(n, -1);
        LL rowLeft = n;
        LL colLeft = n;
        LL ret = 0;
        reverse(queries.begin(), queries.end());
        for (auto & q: queries)
        {
            int type = q[0], idx = q[1], val = q[2];
            if (type==0)
            {
                if (row[idx]!=-1) continue;
                row[idx] = val;
                ret += rowLeft * val;
                colLeft--;
            }
            else
            {
                if (col[idx]!=-1) continue;
                col[idx] = val;
                ret += colLeft * val;
                rowLeft--;                
            }
        }
        return ret;
    }
};
