class Solution {
public:
    int maxJumps(vector<int>& arr, int d) 
    {
        int n = arr.size();
        vector<int>dp(n,1);

        vector<pair<int,int>>p;
        for (int i=0; i<n; i++)
            p.push_back({arr[i],i});
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        for (auto [height, idx]: p)
        {            
            for (int i=idx+1; i<=min(n-1,idx+d); i++)
            {
                if (arr[i] >= arr[idx]) break;                                
                dp[i] = max(dp[i], dp[idx]+1);
            }            
            for (int i=idx-1; i>=max(0, idx-d); i--)
            {
                if (arr[i] >= arr[idx]) break;                                
                dp[i] = max(dp[i], dp[idx]+1);
            }
        }

        int ret = 0;
        for (int i=0; i<n; i++)
            ret = max(ret, dp[i]);
        return ret;
    }
};
