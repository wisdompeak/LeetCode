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
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        int i = 0;
        multiset<int>Set;
        vector<int>rets(queries.size());
        for (auto q: qs)
        {
            while (i<intervals.size() && intervals[i][0] <= q.first)
            {
                pq.push({intervals[i][1], intervals[i][1]-intervals[i][0]+1});
                Set.insert(intervals[i][1]-intervals[i][0]+1);
                i++;
            }
                        
            while (pq.size()>0 && pq.top().first < q.first)
            {
                Set.erase(Set.find(pq.top().second));
                pq.pop();
            }
            
            if (Set.size()>0)
                rets[q.second] = *Set.begin();
            else
                rets[q.second] = -1;
        }
        return rets;        
    }
};
