class Solution {
public:
    int maxSizeSlices(vector<int>& slices) 
    {
        int n = slices.size();
        return max(helper(0, n-2, n/3, slices), helper(1,n-1, n/3, slices));
    }
    
    int helper(int st, int en, int k, vector<int>& slices)
    {        
        vector<int>dp0(k+1);
        vector<int>dp1(k+1);
        
        for (int i=st; i<=en; i++)
            for (int j=min(k,i-st+1); j>=1; j--)
            {
                dp0[j] = max(dp0[j], dp1[j]);
                dp1[j] = dp0[j-1] + slices[i];
            }
        
        return max(dp0[k], dp1[k]);
    }
};
