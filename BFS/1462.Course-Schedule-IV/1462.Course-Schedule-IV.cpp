class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        vector<unordered_set<int>>next(n);
        vector<int>inDegree(n,0);
        vector<unordered_set<int>>preSet(n);
        
        for (auto edge: prerequisites)
        {
            next[edge[0]].insert(edge[1]);
            inDegree[edge[1]] += 1;
        }
        
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            preSet[i].insert(i);
            if (inDegree[i]==0)
                q.push(i);
        }            
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for (int next: next[cur])
            {
                for (auto x: preSet[cur])
                    preSet[next].insert(x);
                
                inDegree[next] -= 1;
                if (inDegree[next]==0)
                    q.push(next);
            }
        }
        
        vector<bool>rets;
        for (auto query: queries)
        {
            rets.push_back(preSet[query[1]].find(query[0])!=preSet[query[1]].end());
        }
        return rets;
    }
};
