class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        auto visited = vector<vector<bool>>(n,vector<bool>(1<<n,0));
        
        queue<pair<int,int>>q; // {node, visitedNodes}
        for (int i=0; i<n; i++)
        {
            q.push({i, 1<<i});
            visited[i][1<<i] = 1;
        }
       
        int step = -1;
        while(!q.empty())
        {
            step++;
            int len = q.size();
            while (len--)
            {
                int node = q.front().first;
                int state = q.front().second;
                q.pop();
                
                for (auto& nextNode:graph[node])
                {
                    int nextState = (state | (1<<nextNode));
                    if (visited[nextNode][nextState]==1)
                        continue;
                    if (nextState == (1<<n)-1)
                        return step+1;
                    q.push({nextNode, nextState});
                    visited[nextNode][nextState] = 1;
                }
            }            
        }
        
        return 0;
        
    }
};
