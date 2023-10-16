class Solution {
    vector<long long>presum;
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) 
    {
        banned.erase(std::unique(banned.begin(), banned.end()),banned.end());
        sort(banned.begin(), banned.end());

        presum.resize(banned.size());
        for (int i=0; i<banned.size(); i++)
            presum[i] = (i==0?0:presum[i-1]) + banned[i];

        int left = 0, right = n;
        while (left < right)
        {
            int mid = right - (right-left)/2;
            if (More(mid, banned, n, maxSum))
                right = mid-1;
            else
                left = mid;
        }
        int m = left;
        int t = upper_bound(banned.begin(), banned.end(), m) - banned.begin();
        return m - t;
    }

    bool More(long long m, vector<int>& banned, int n, long long maxSum)
    {
        int t = upper_bound(banned.begin(), banned.end(), m) - banned.begin();
        long long sum = (1+m)*m/2 - (t==0?0:presum[t-1]);
        return sum > maxSum;
    }
};
