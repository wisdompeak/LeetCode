
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

        set<tuple<double, int>>Set; // {dist, node}
        Set.insert({0, start});
        vector<double>prob(n,-1);

        while (!Set.empty())
        {
            double dist = get<0>(*Set.begin());
            int curNode = get<1>(*Set.begin());            
            Set.erase(Set.begin());

            if (prob[curNode]!=-1) continue;
            prob[curNode] = dist;
            
            if (curNode==end) return exp(-prob[curNode]);

            for (auto next: Next[curNode])
            {
                int nextNode = next.first;
                double edge = next.second;
                if (prob[nextNode]!=-1) continue;
                Set.insert({dist + edge, nextNode});
            }
        }

        return 0;
    }
};
