class Solution {
public:
    int longestCycle(vector<int>& edges) 
    {
        int n = edges.size();
        vector<int>indegree(n);
        for (int i=0; i<n; i++)
        {            
            int a = i, b= edges[i];
            if (b!=-1)
                indegree[b]++;            
        }        
        
        vector<int>visited(n);
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            if (indegree[i]==0)
            {
                q.push(i);
                visited[i] = 1;
            }
                
        }        
        
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            int y = edges[x];
            if (y==-1) continue;
            indegree[y]--;
            if (indegree[y]==0)
            {
                q.push(y);            
                visited[y] = 1;
            }                
        }
        
        
        int ret = -1;
        for (int i=0; i<n; i++)
        {
            if (visited[i]==1) continue;
            
            int j = i;
            int len = 0;
            while (visited[j]==0)
            {
                visited[j] = 1;
                len++;                
                j = edges[j];
            }
            ret = max(ret, len);
        }
        
        return ret;
    }
};
