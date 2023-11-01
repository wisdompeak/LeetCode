class Solution {
public:
    long long maxScore(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int>arr(n);
        for (int i=0; i<n; i++)
            arr[i] = prices[i] - (i+1);
        
        unordered_map<int,long long>Map;
        for (int i=0; i<n; i++)
            Map[arr[i]]+=prices[i];

        long long ret = 0;
        for (auto [k,v]: Map)
            ret = max(ret, v);

        return ret;
        
    }
};
