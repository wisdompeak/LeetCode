class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
    {
        unordered_map<int,unordered_set<int>>graph;
        for (int i=0; i<edges.size(); i++)
        {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
        }
        
        unordered_set<int>candidates;
        for (int i=0; i<n; i++)
            candidates.insert(i);
        
        while (candidates.size()>2)
        {
            vector<int>temp;
            
            for (auto a:candidates)
            {
                if (graph[a].size()==1)
                    temp.push_back(a);
            }
            for (auto a:temp)
            {
                candidates.erase(a);
                for (auto b:graph[a])
                    graph[b].erase(a);
            }
        }
        
        vector<int>results;
        for (auto a:candidates) results.push_back(a);
        
        return results;
        
    }
};
