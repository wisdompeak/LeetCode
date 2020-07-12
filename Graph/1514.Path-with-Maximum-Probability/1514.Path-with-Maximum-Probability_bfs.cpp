class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<vector<pair<int, double>>>Next(n);
        for (int i=0; i<edges.size(); i++)
        {
            Next[edges[i][0]].push_back({edges[i][1], succProb[i]});
            Next[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double>prob(n);
        prob[start] = 1;
        queue<int>q;
        q.push(start);
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto next: Next[cur])
            {
                if (prob[next.first] >= prob[cur] * next.second) continue;
                prob[next.first] = prob[cur]*next.second;
                q.push(next.first);
            }
        }
        return prob[end];
        
    }
};
