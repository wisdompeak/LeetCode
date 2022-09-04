class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols)     
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int>nums;
        for (int i=0; i<m; i++)
        {
            int num = 0;
            for (int j=0; j<n; j++)
                num = num*2 + (mat[i][j]);
            nums.push_back(num);
        }
        
        int ret = 0;

        int state = (1 << cols) - 1;                    
        while (state < (1 << n))
        {
            int count = 0;
            for (int x: nums)
                if ((state&x)==x)
                    count++;
            ret = max(ret, count);            

            int c = state & - state;
            int r = state + c;
            state = (((r ^ state) >> 2) / c) | r;
        }

        return ret;
        
    }
};
