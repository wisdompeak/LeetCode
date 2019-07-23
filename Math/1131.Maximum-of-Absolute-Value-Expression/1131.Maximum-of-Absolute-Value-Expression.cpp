class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) 
    {
        int N = arr1.size();
        int  a[N][3];
        for (int i=0; i<N; i++)
        {
            a[i][0] = arr1[i];
            a[i][1] = arr2[i];
            a[i][2] = i;
        }
        
        int ans = 0, mi, mx, t;
        for (int s=0; s<(1<<3); s++) 
        {
            mi = INT_MAX, mx = INT_MIN;
            for (int i=0; i<N; i++) 
            {
                t = 0;
                for (int j=0; j<3; j++)
                    if ((1<<j) & s) 
                        t += a[i][j];
                    else 
                        t -= a[i][j];
                mi = min(mi, t);
                mx = max(mx, t);
            }
            ans = max(ans, mx-mi);
        }
        
        return ans;

    }
};
