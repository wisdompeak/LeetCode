class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
    {
        if (n==1) return {0};
        if (n==2) return {0,1};
        
        unordered_map<int,int>Degree;
        unordered_map<int,vector<int>>Up;
        
        for (auto edge:edges)
        {
            Degree[edge.first]++;
            Degree[edge.second]++;
            Up[edge.second].push_back(edge.first);
            Up[edge.first].push_back(edge.second);
        }
        
        queue<int>q;
        for (auto a:outDegree)
            if (a.second==1) q.push(a.first);
        
        int count = 0;
        while (!q.empty())
        {
            int k = q.size();
            for (int i=0; i<k; i++)
            {
                int node = q.front();
                q.pop();
                count++;

                for (auto upNode: Up[node])
                {
                    Degree[upNode]--;
                    if (Degree[upNode]==1)
                        q.push(upNode);
                }
            }
                       
            if (count+q.size()==n)
            {
                vector<int>results;
                while (!q.empty())
                {
                    results.push_back(q.front());
                    q.pop();
                }
                return results;
            }
        }
    }
};
