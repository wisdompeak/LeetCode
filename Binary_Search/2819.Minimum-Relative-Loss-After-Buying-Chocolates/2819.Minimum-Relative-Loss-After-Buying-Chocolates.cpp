using LL = long long;
class Solution {
    LL presum[100005];
public:
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries) 
    {
        int n = prices.size();
        sort(prices.begin(), prices.end());

        presum[0] = prices[0];
        for (int i=1; i<n; i++)
            presum[i] = presum[i-1]+prices[i];

        vector<LL>rets;
        for (auto& arr: queries)
        {
            LL k = arr[0], m = arr[1];
            int left = 0, right = m;
            while (left < right)
            {
                int mid = right - (right-left)/2;
                if (mid==0 || mid==m) break;
                if (prices[mid-1] < 2*k - prices[n-(m-mid)])
                    left = mid;
                else
                    right = mid-1;
            }
            int p = left;
            LL ans1 = rangeSum(0, p-1) + 2*k*(m-p) - rangeSum(n-(m-p), n-1);            
            p++;
            LL ans2 = rangeSum(0, p-1) + 2*k*(m-p) - rangeSum(n-(m-p), n-1);
            rets.push_back(min(ans1, ans2));
        }

        return rets;        
    }

    LL rangeSum(int a, int b)
    {
        if (a>b) return 0LL;
        if (a==0)
            return presum[b];
        else
            return presum[b]-presum[a-1];
    }
};
