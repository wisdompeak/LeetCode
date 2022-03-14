using PDI = pair<double, int>;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<vector<pair<int, double>>>Next(n);
        for (int i=0; i<edges.size(); i++)
        {
            Next[edges[i][0]].push_back({edges[i][1], -log(succProb[i])});
            Next[edges[i][1]].push_back({edges[i][0], -log(succProb[i])});
        }

        vector<double>prob(n,-1);
        priority_queue<PDI, vector<PDI>, greater<>> pq;
        pq.push({0, start});
        
        while (!pq.empty())
        {
            auto [dist, curNode] = pq.top();
            pq.pop();

            if (prob[curNode]!=-1) continue;
            prob[curNode] = dist;
            
            if (curNode==end) return exp(-prob[curNode]);

            for (auto next: Next[curNode])
            {
                int nextNode = next.first;
                double edge = next.second;
                if (prob[nextNode]!=-1) continue;
                pq.push({dist + edge, nextNode});
            }
        }
        
        return 0;
    }
};
