class Solution {
    int visited[12][1<<12];
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n=graph.size();        
                       
        queue<pair<int,int>>q;        
                
        for (int i=0; i<n; i++)
        {            
            q.push({i,1<<i});
            visited[i][1<<i] = 1;
        }
        
        int step = 0;
        while (q.size()!=0)
        {
            int len = q.size();
            while (len--)
            {
                auto [cur, state] = q.front();
                q.pop();
                
                for (int i: graph[cur])
                {                    
                    if ((state | (1<<i)) == (1<<n)-1) return step+1;                        
                    if (visited[i][state]==1) continue;
                    visited[i][state] = 1;
                    q.push({i, state | (1<<i)});
                }                
            }
            step++;            
        }
        
        return 0;
    }

};
