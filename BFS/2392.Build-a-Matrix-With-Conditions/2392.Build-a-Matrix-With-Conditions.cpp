class Solution {
public:
    vector<int>topo(int k, vector<vector<int>>& conditions)
    {
        vector<int>indegree(k+1);
        vector<vector<int>>next(k+1);
        for (auto& x: conditions)
        {
            next[x[0]].push_back(x[1]);
            indegree[x[1]] += 1;            
        }
    
        queue<int>q;        
        for (int i=1; i<=k; i++)            
            if (indegree[i]==0)            
                q.push(i);
            
        vector<int>rets;                
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            rets.push_back(cur);
            for (auto x: next[cur])
            {
                indegree[x]--;
                if (indegree[x]==0)
                    q.push(x);
            }
        }        
        
        if (rets.size() != k) return {};
        
        return rets;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        vector<int>row = topo(k, rowConditions);
        vector<int>col = topo(k, colConditions);
                
        if (row.empty() || col.empty()) return {};
        
        vector<pair<int,int>>pos(k+1);
        for (int i=0; i<k; i++)
            pos[row[i]].first = i;
        
        for (int i=0; i<k; i++)
            pos[col[i]].second = i;
        
        vector<vector<int>>matrix(k, vector<int>(k));
        for (int i=1; i<=k; i++)        
            matrix[pos[i].first][pos[i].second] = i;
        
        return matrix;
        
    }
};
