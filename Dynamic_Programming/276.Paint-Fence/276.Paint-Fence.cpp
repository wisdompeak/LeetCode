class Solution {
public:
    int numWays(int n, int k) 
    {
        if (n==0) return 0;
        if (n==1) return k;
        int same = k;
        int diff = k*(k-1);
        for (int i=2; i<n; i++)
        {
            int same_temp = same;
            int diff_temp = diff;
            diff = same_temp*(k-1) + diff_temp*(k-1);
            same = diff_temp;
        }
        return same+diff;
    }
};
