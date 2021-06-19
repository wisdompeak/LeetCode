typedef pair<int,int> PII;
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) 
    {
        vector<PII>qs;
        for (int i=0; i<queries.size(); i++)
            qs.push_back({queries[i], i});

        sort(qs.begin(), qs.end());
        sort(intervals.begin(), intervals.end());

        vector<int>rets(qs.size(), -1);
        priority_queue<PII, vector<PII>, greater<>>pq;
        int i = 0;
        
        for (auto q: qs)
        {
            auto [t, idx] = q;
            while (i<intervals.size() && intervals[i][0] <= t)
            {
                pq.push({intervals[i][1]-intervals[i][0]+1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < t)
                pq.pop();

            if (!pq.empty())
                rets[idx] = pq.top().first;
        }

        return rets;
    }
};
