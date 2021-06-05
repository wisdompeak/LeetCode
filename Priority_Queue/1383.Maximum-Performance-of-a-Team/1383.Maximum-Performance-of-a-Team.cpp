class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int,int>>p;
        for (int i=0; i<n; i++)
            p.push_back({efficiency[i], speed[i]});
        sort(p.rbegin(), p.rend());
        
        priority_queue<int, vector<int>, greater<>>pq;
        long long ret = 0;
        long long speedsum = 0;
        long long M = 1e9+7;
        for (int i=0; i<n; i++)
        {
            speedsum += p[i].second;
            pq.push(p[i].second);
            if (pq.size()>k)
            {
                speedsum -= pq.top();
                pq.pop();
            }
            ret = max(ret, p[i].first*speedsum);
        }
        return ret % M;
    }
};
