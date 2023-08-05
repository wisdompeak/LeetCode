using PII = pair<int,int>;
using LL = long long;
class Solution {
    LL dp[1005][1005];
    LL presum[1005];
    int n;
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) 
    {        
        n = nums1.size();
        
        vector<PII>arr;
        for (int i=0; i<nums1.size(); i++)
            arr.push_back({nums1[i], nums2[i]});
        sort(arr.begin(), arr.end(), [](PII& a, PII &b){return a.second < b.second;});
        
        arr.insert(arr.begin(), {0,0});
                
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+arr[i].second;
        
        dp[0][0] = 0;
        for (int i=1; i<=n; i++)
            for (int j=0; j<=n; j++)
            {
                dp[i][j] = INT_MAX/2;
                dp[i][j] = min(dp[i][j], dp[i-1][j] + arr[i].first+arr[i].second*j);
                if (j>=1) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + presum[i-1]);                
            }        
        
        for (int t=0; t<=n; t++)
            if (dp[n][t]<=x) return t;
        return -1;
    }
};
