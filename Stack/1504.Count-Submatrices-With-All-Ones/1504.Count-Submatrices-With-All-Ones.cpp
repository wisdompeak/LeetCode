class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<int>h(n+1, 0);

        int ret = 0;

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                h[j+1] = (mat[i][j] == 1? (h[j+1]+1):0);

            stack<int>stk;
            stk.push(0);
            int c = 0;
            for (int j=1; j<=n; j++)
            {
                while (!stk.empty() && h[stk.top()] > h[j])
                {
                    int p1 = stk.top();
                    stk.pop();
                    int p2 = stk.top();
                    c =  c - (p1-p2)*(h[p1]-h[j]);
                }
                c += h[j];
                ret += c;
                stk.push(j);
            }
        }

        return ret;        
    }
};
