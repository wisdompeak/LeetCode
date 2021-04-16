class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) 
    {
        vector<vector<int>>next(N+1);
        vector<int>inDegree(N+1,0);
        for (auto x:relations)
        {
            next[x[0]].push_back(x[1]);
            inDegree[x[1]] += 1;
        }
        
        queue<int>q;        
        int count = 0;
        for (int i=1; i<=N; i++)
        {
            if (inDegree[i]==0)
            {
                count += 1;
                q.push(i);
            }                
        }
                
        int step = 0;
        
        while (!q.empty())
        {
            int len = q.size();
            step += 1;
            while (len--)
            {
                int cur = q.front();
                q.pop();
                for (auto next: next[cur])
                {
                    inDegree[next] -= 1;
                    if (inDegree[next]==0)
                    {
                        q.push(next);
                        count++;
                    }                        
                }
            }                        
        }
        
        if (count!=N)
            return -1;
        else
            return step;
    }
};
