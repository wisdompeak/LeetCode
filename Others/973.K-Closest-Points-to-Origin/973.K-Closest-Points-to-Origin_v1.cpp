using LL = long long;
using PLI = pair<LL, int>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        priority_queue<PLI>pq;
        for (int i=0; i<points.size(); i++)
        {
            long long x1 = points[i][0];
            long long x2 = points[i][1];
            long long d = x1*x1+x2*x2;
            pq.push({d, i});
            
            if (pq.size() > K)
                pq.pop();
        }
        
        vector<vector<int>>results;
        while (!pq.empty())
        {
            int id = pq.top().second;
            results.push_back(points[id]);
            pq.pop();
        }
        return results;
    }
};
