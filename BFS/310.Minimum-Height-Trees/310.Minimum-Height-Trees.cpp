class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if (n==1) return {0};
        if (n==2) return {0,1};
                
        vector<int>inDegree(n);   
        vector<vector<int>>next(n);
        for (auto edge:edges)
        {
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);            
        }
        
        queue<int>q;
        vector<int>visited(n);
        for (int i=0; i<n; i++)
        {
            if (inDegree[i]==1)            
                q.push(i);            
        }                
        
        int count = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int cur = q.front();
                q.pop();
                visited[cur] = 1;
                count++;                
                for (int nxt: next[cur])
                {
                    inDegree[nxt]--;
                    if (inDegree[nxt]==1)
                        q.push(nxt);
                }       
            }          
            if (count==n-1 || count==n-2)
                    break;
        }
        
        vector<int>rets;
        for (int i=0; i<n; i++)
        {
            if (visited[i]==0)
                rets.push_back(i);
        }
        
        return rets;
        
    }
};
