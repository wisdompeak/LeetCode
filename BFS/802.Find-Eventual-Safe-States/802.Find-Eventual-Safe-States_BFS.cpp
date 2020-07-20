class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>outDegree(n,0);
        vector<vector<int>>prev(n);
        for (int i=0; i<n; i++)        
            for (auto j: graph[i])
            {
                prev[j].push_back(i);
                outDegree[i]+=1;
            }       

        vector<int>ret;         
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            if (outDegree[i]==0) 
            {
                q.push(i);
                ret.push_back(i);
            }
        }
            
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int prev: prev[cur])
            {
                outDegree[prev] -= 1;
                if (outDegree[prev]==0)
                {
                    q.push(prev);
                    ret.push_back(prev);                    
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;        
    }

};
