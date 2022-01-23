class Solution {
public:
    int maximumInvitations(vector<int>& favorite) 
    {
        int n = favorite.size();
        vector<int>indegree(n);
        for (int i=0; i<n; i++)
            indegree[favorite[i]]++;

        queue<int>q;        
        vector<int>visited(n);
        vector<int>depth(n,1);
        for (int i=0; i<n; i++)
        {
            if (indegree[i]==0)
            {
                depth[i] = 1;
                visited[i] = 1;
                q.push(i);
            }                
        }
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            int nxt = favorite[cur];
            indegree[nxt]--;
            if (indegree[nxt]==0)            
            {
                q.push(nxt);                                      
                visited[nxt] = 1;
            }                
            depth[nxt] = depth[cur]+1;
        }

        int max_circle_size = 0;                
        int max_link_size = 0;        
        for (int i=0; i<n; i++)
        {
            if (visited[i]==1) continue;
            int j = i;
            int count = 0;
            while (visited[j]==0)
            {
                count++;
                visited[j] = 1;
                j = favorite[j];
            }
            if (count>2)
                max_circle_size = max(max_circle_size, count);
            else if (count==2)
                max_link_size += depth[i]+depth[favorite[i]];
        }

        return max(max_circle_size, max_link_size);        
    }
};
