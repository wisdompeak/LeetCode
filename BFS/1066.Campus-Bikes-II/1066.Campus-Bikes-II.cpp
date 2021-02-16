typedef pair<int,int> PII;

class Solution {
    int dist[10][10];
    int visited[1024];
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        int m = workers.size();
        int n = bikes.size();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int x1=workers[i][0];
                int y1=workers[i][1];
                int x2=bikes[j][0];
                int y2=bikes[j][1];
                dist[i][j] = abs(x1-x2)+abs(y1-y2);
            }
        
        priority_queue<PII, vector<PII>, greater<>>pq;        
        pq.push({0, 0});        
        
        while (!pq.empty())
        {
            auto [cost, state] = pq.top();
            pq.pop();
                        
            if (visited[state]) continue;
            visited[state] = 1;
            
            int i = __builtin_popcount(state);
            if (i==m) return cost;
                
            for (int j=0; j<bikes.size(); j++)
            {
                if ((state>>j)&1) continue;
                int newState = state+(1<<j);
                if (visited[newState]) continue;                    
                pq.push({cost+dist[i][j], newState});
            }
        }
                
        return 0;
    }
};
