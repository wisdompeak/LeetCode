class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int>rets(n, 1);
        for (int i=1; i<n; i++)
        {
            if (ratings[i]>ratings[i-1])
                rets[i] = max(rets[i], rets[i-1]+1);
        }
        for (int i=n-2; i>=0; i--)
        {
            if (ratings[i]>ratings[i+1])
                rets[i] = max(rets[i], rets[i+1]+1);
        }
        int sum = accumulate(rets.begin(), rets.end(), 0);
        return sum;
    }
};
