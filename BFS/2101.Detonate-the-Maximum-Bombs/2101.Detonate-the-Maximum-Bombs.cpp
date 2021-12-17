using LL = long long;
class Solution {
    vector<int>next[100];
public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n = bombs.size();
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                LL dx = bombs[i][0]-bombs[j][0];
                LL dy = bombs[i][1]-bombs[j][1];
                LL r = bombs[i][2];
                if (dx*dx+dy*dy<=r*r)
                    next[i].push_back(j);
            }

        int ret = 0;        
        for (int s=0; s<n; s++)
        {
            queue<int>q;
            q.push(s);
            vector<int>visited(n);
            visited[s] = 1;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int i: next[cur])
                {
                    if (visited[i]) continue;
                    q.push(i);
                    visited[i] = 1;
                }
            }
            int count = 0;
            for (int i=0; i<n; i++)
                count+=visited[i];
            ret = max(count, ret);
        }
        return ret;
        
    }
};
