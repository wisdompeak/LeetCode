class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) 
    {
        int n = arr1.size();
        arr1.insert(arr1.begin(),0);
        sort(arr2.begin(),arr2.end());
        auto dp = vector<vector<int>>(n+1, vector<int>(n+1,INT_MAX));
        dp[0][0] = INT_MIN;

        for (int i=1; i<=n; i++)
            for (int k=0; k<=i; k++)
            {
                if (arr1[i] > dp[i-1][k])
                    dp[i][k] = min(dp[i][k], arr1[i]);

                if (k>=1)
                {
                    auto iter = upper_bound(arr2.begin(), arr2.end(), dp[i-1][k-1]);
                    if (iter!=arr2.end()) dp[i][k] = min(dp[i][k], *iter);
                }                
            }

        int ret = INT_MAX;
        for (int k=0; k<=n; k++)
            if (dp[n][k]!=INT_MAX) {
                ret = k;
                break;
            }

        return ret == INT_MAX ? -1: ret;
    }
};
