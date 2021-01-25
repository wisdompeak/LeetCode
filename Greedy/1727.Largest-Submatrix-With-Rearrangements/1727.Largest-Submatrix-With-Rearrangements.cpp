class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>a(n,0);
        int ret = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (matrix[i][j]==1)
                    a[j] = a[j]+1;
                else
                    a[j] = 0;                    
            }
            auto b = a;
            sort(b.begin(), b.end());
            reverse(b.begin(), b.end());
            int h = INT_MAX;
            for (int j=0; j<n; j++)
            {
                h = min(h, b[j]);
                ret = max(ret, h*(j+1));
            }
        }
        return ret;        
    }
};
