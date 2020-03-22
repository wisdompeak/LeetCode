class Solution {
public:
    int maxSizeSlices(vector<int>& slices) 
    {
        int n = slices.size();
        return max(helper(0, n-2, n/3, slices), helper(1,n-1, n/3, slices));
    }
    
    int helper(int st, int en, int k, vector<int>& slices)
    {
        vector<int>f(k+1,0); // f[i]: the maximum gain by the current round if we take i slices, and we do take the current slice.
        vector<int>g(k+1,0); // g[i]: the maximum gain by the current round if we take i slices, and we do NOT take the current slice.
        
        for (int i=st; i<=en; i++)
            for (int j=min(k,i-st+1); j>=1; j--)
            {
                g[j] = max(g[j], f[j]);
                f[j] = g[j-1] + slices[i];                                
            }
        
        return max(f[k], g[k]);        
    }
};
